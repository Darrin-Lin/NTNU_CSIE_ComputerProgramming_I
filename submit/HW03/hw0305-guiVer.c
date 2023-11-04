#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"

#define TITLE "Super Dice Bros. - Brawl"
#define Width 1000
#define Height 600
#define rule "Welcome to Super Dice Bros. - Brawl!\nThere are also some information in README.\nYou can click the button to choose the action.\nThe actions are:\nClick 1d6 to roll a dice with 6 side.\nClick Adx to roll A dice with X sides each.\nClick AdXkY+B to roll A dice with X sides each, and choose Y dice and add B for the bonus.\nClick AdXkhHklLkcC+B to roll A dice with X sides each, keeping the H highest, the L lowest, \nand C of the player’s choice and add B for the bonus.\n\nrange:\nA: 0~10\nX: 2~100\nB: -10~10\nY: 0~A\nH: 0~A\nL: 0~A-H\nC: 0~A-(L+H)"
#define key_position (Height / 2)
// this program is edit ver of https://docs.gtk.org/gtk3/getting_started.html
static GtkWidget *window;
static GtkWidget *button[12];
static GtkWidget *fix;
static GtkWidget *label;
static GtkWidget *dices[20];
static GtkWidget *input_label[10];
static GtkWidget *enter_button[10];
static GtkWidget *input[10];
static GtkWidget *show_label[10];
static GtkWidget *final_label;

static void clear_all_button(/*GtkApplication *app, gpointer data*/);
static void clear_string();
static void result_init();
static void set_init();
static void start_game(GtkApplication *app, gpointer data);
static void choose_game(GtkApplication *app, gpointer data);
static void quit_again();
static void Id6_window(GtkApplication *app, gpointer data);
static void AdX_window(GtkApplication *app, gpointer data);
static void AdX_roll(GtkApplication *app, gpointer data);
static void AdXkY_add_B_window(GtkApplication *app, gpointer data);
static void AdXkY_add_B_roll(GtkApplication *app, gpointer data);
static void AdXkY_add_B_count(GtkApplication *app, gpointer data);
static void AdXkhHklLkcC_add_B_window(GtkApplication *app, gpointer data);
static void AdXkhHklLkcC_add_B_roll(GtkApplication *app, gpointer data);
static void AdXkhHklLkcC_add_B_count(GtkApplication *app, gpointer data);
static void enterA();
static void enterX();
static void enterY();
static void enterB();
static void enterC();
static void enterH();
static void enterL();

static char dice_num[10];
static int32_t inp_num[10] = {0};
static int32_t num_choose = 0;
static int32_t result[10] = {0};
static int32_t discard = 0;
static int32_t remain[10] = {0};
static int8_t set[10] = {0};

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("darrin.s.Game", G_APPLICATION_FLAGS_NONE); // WSL(Ubuntu) //G_APPLICATION_FLAGS_NONE //EndeavourOS //G_APPLICATION_DEFAULT_FLAGS
	// app = gtk_application_new("darrin.s.Game", G_APPLICATION_DEFAULT_FLAGS); // WSL(Ubuntu) //G_APPLICATION_FLAGS_NONE //EndeavourOS //G_APPLICATION_DEFAULT_FLAGS

	g_signal_connect(app, "activate", G_CALLBACK(start_game), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
static void start_game(GtkApplication *app, gpointer data)
{
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), TITLE);
	gtk_window_set_default_size(GTK_WINDOW(window), Width, Height);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	fix = gtk_fixed_new();
	button[0] = gtk_button_new_with_label("Press here to start.");
	// g_signal_connect(button[0], "clicked", G_CALLBACK(clear_all_button), NULL);
	g_signal_connect_after(button[0], "clicked", G_CALLBACK(choose_game), NULL);
	button[1] = gtk_button_new_with_label("Press here to quit.");
	g_signal_connect_swapped(button[1], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2 - 50 - 100, Height / 2);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2 - 50 - 100, Height * 2 / 3);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	return;
}

static void choose_game(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	label = gtk_label_new(rule);
	button[0] = gtk_button_new_with_label("1d6");
	g_signal_connect(button[0], "clicked", G_CALLBACK(Id6_window), NULL);
	button[1] = gtk_button_new_with_label("AdX");
	g_signal_connect(button[1], "clicked", G_CALLBACK(AdX_window), NULL);
	button[2] = gtk_button_new_with_label("AdXkY+B");
	g_signal_connect(button[2], "clicked", G_CALLBACK(AdXkY_add_B_window), NULL);
	button[3] = gtk_button_new_with_label("AdXkhHklLkcC+B");
	g_signal_connect(button[3], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B_window), NULL);
	button[4] = gtk_button_new_with_label("Press here to quit.");
	g_signal_connect_swapped(button[4], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2 - 50 - 400, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2 - 50 - 200, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[2], Width / 2 - 50, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[3], Width / 2 - 50 + 200, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[4], Width / 2 - 50 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), label, 0, 0);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	return;
}
static void clear_string()
{
	for (int32_t i = 0; i < 10; i++)
	{
		dice_num[i] = '\0';
	}
	return;
}
static void quit_again()
{
	button[10] = gtk_button_new_with_label("Press here to quit.");
	button[11] = gtk_button_new_with_label("Play again.");
	g_signal_connect_swapped(button[10], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	g_signal_connect(button[11], "clicked", G_CALLBACK(choose_game), NULL);
	gtk_fixed_put(GTK_FIXED(fix), button[10], Width / 2 - 50 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), button[11], Width / 2 - 50 + 100, Height * 2 / 3 + 100);
	// quit and again
	gtk_widget_show_all(window);
	return;
}

static void enterA()
{
	char numA[10];
	sprintf(numA, "%s", gtk_entry_get_text(GTK_ENTRY(input[0])));
	inp_num[0] = 0;
	for (size_t i = 0; numA[i] != '\0'; i++)
	{
		inp_num[0] = 10 * inp_num[0] + (numA[i] - '0');
	}
	if (inp_num[0] > 10 || inp_num[0] < 1)
	{
		input_label[0] = gtk_label_new("Please enter A in range 0~10.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[0], Width * 1 / 3 - 50, 75);
		gtk_widget_show_all(window);
		inp_num[0] = 0;
		set[0] = 0;
		return;
	}
	else
		set[0] = 1;
	return;
	// fprintf(stderr, "%d\n", inp_num[0]);
}
static void enterX()
{
	char numX[10];
	sprintf(numX, "%s", gtk_entry_get_text(GTK_ENTRY(input[1])));
	inp_num[1] = 0;
	for (size_t i = 0; numX[i] != '\0'; i++)
	{
		inp_num[1] = 10 * inp_num[1] + (numX[i] - '0');
	}
	if (inp_num[1] < 2 || inp_num[1] > 100)
	{
		input_label[1] = gtk_label_new("Please enter X in range 2~100.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[1], Width * 1 / 3 - 50, 225);
		gtk_widget_show_all(window);
		inp_num[1] = 0;
		set[1] = 0;
		return;
	}
	else
		set[1] = 1;
	return;
	// fprintf(stderr, "%d\n", inp_num[1]);
}
static void enterY()
{
	char numY[10];
	sprintf(numY, "%s", gtk_entry_get_text(GTK_ENTRY(input[2])));
	inp_num[2] = 0;
	for (size_t i = 0; numY[i] != '\0'; i++)
	{
		inp_num[2] = 10 * inp_num[2] + (numY[i] - '0');
	}
	if (inp_num[2] > inp_num[0] || inp_num[2] < 0)
	{
		input_label[2] = gtk_label_new("Please enter Y in range 0~A.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[2], Width * 1 / 3 - 50, 375);
		gtk_widget_show_all(window);
		inp_num[2] = 0;
		set[2] = 0;
		return;
	}
	else
		set[2] = 1;
	return;
	// fprintf(stderr, "%d\n", inp_num[2]);
}
static void enterB()
{
	char numB[10];
	sprintf(numB, "%s", gtk_entry_get_text(GTK_ENTRY(input[3])));
	inp_num[3] = 0;
	int neg = 1;
	for (size_t i = 0; numB[i] != '\0'; i++)
	{
		if (i == 0 && numB[0] == '-')
			neg = -1;
		else
			inp_num[3] = 10 * inp_num[3] + (numB[i] - '0');
	}
	inp_num[3] *= neg;
	if (inp_num[3] > 10 || inp_num[3] < -10)
	{
		input_label[3] = gtk_label_new("Please enter B in range -10~10.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[3], Width * 2 / 3 - 50, 375);
		gtk_widget_show_all(window);
		inp_num[3] = 0;
		set[3] = 0;
		return;
	}
	else
		set[3] = 1;
	// fprintf(stderr, "%d\n", inp_num[3]);
	return;
}
static void enterC()
{
	char numY[10];
	sprintf(numY, "%s", gtk_entry_get_text(GTK_ENTRY(input[2])));
	inp_num[2] = 0;
	for (size_t i = 0; numY[i] != '\0'; i++)
	{
		inp_num[2] = 10 * inp_num[2] + (numY[i] - '0');
	}
	if (inp_num[2] > inp_num[0] - inp_num[4] - inp_num[5] || inp_num[2] < 0)
	{
		input_label[2] = gtk_label_new("Please enter C in range 0~(A-H-L).");
		gtk_fixed_put(GTK_FIXED(fix), input_label[2], Width * 1 / 3 - 50, 375);
		gtk_widget_show_all(window);
		inp_num[2] = 0;
		set[2] = 0;
		return;
	}
	else
		set[2] = 1;
	return;
	// fprintf(stderr, "%d\n", inp_num[2]);
}
static void enterH()
{
	char numH[10];
	sprintf(numH, "%s", gtk_entry_get_text(GTK_ENTRY(input[4])));
	inp_num[4] = 0;
	for (size_t i = 0; numH[i] != '\0'; i++)
	{
		inp_num[4] = 10 * inp_num[4] + (numH[i] - '0');
	}
	if (inp_num[4] > inp_num[0] || inp_num[4] < 0)
	{
		input_label[4] = gtk_label_new("Please enter H in range 0~A.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[4], Width * 2 / 3 - 50, 75);
		gtk_widget_show_all(window);
		inp_num[4] = 0;
		set[4] = 0;
		return;
	}
	else
		set[4] = 1;
	return;
	// fprintf(stderr, "%d\n", inp_num[4]);
}
static void enterL()
{
	char numL[10];
	sprintf(numL, "%s", gtk_entry_get_text(GTK_ENTRY(input[5])));
	inp_num[5] = 0;
	for (size_t i = 0; numL[i] != '\0'; i++)
	{
		inp_num[5] = 10 * inp_num[5] + (numL[i] - '0');
	}
	if (inp_num[5] > inp_num[0] - inp_num[4] || inp_num[5] < 0)
	{
		input_label[5] = gtk_label_new("Please enter L in range 0~A-H.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[5], Width * 2 / 3 - 50, 225);
		gtk_widget_show_all(window);
		inp_num[5] = 0;
		set[5] = 0;
		return;
	}
	else
		set[5] = 1;
	return;
	// fprintf(stderr, "%d\n", inp_num[5]);
}
static void clear_all_button(/*GtkApplication *app, gpointer data*/)
{
	// for (int32_t i = 0; i < 11; i++)
	// {
	// 	if (button[i] != NULL)
	// 		gtk_widget_destroy(button[i]);
	// }
	gtk_widget_destroy(fix);
	return;
}
static void set_init()
{
	for (int32_t i = 0; i < 10; i++)
		set[i] = 0;
	return;
}
static void result_init()
{
	for (int32_t i = 0; i < 10; i++)
	{
		result[i] = 0;
	}
	return;
}


static void Id6_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	srand(time(NULL));
	fix = gtk_fixed_new();
	// final = 0;
	result_init();
	result[0] = dice(6);
	clear_string();
	sprintf(dice_num, "%d", result[0]);
	label = gtk_label_new("1d6 result:");
	dices[0] = gtk_button_new_with_label(dice_num);
	gtk_fixed_put(GTK_FIXED(fix), label, Width / 2 - 50, Height * 1 / 3 - 100);
	gtk_fixed_put(GTK_FIXED(fix), dices[0], Width / 2 - 50, Height * 1 / 3);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	quit_again();
	return;
}
static void AdX_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	set_init();
	fix = gtk_fixed_new();
	input_label[0] = gtk_label_new("Enter A:");
	input[0] = gtk_entry_new();
	enter_button[0] = gtk_button_new_with_label("Enter");
	input_label[1] = gtk_label_new("Enter X:");
	input[1] = gtk_entry_new();
	enter_button[1] = gtk_button_new_with_label("Enter");
	// rolol
	enter_button[9] = gtk_button_new_with_label("Roll");
	g_signal_connect(enter_button[9], "clicked", G_CALLBACK(AdX_roll), NULL);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[9], Width * 1 / 3 - 50, Height - 50);
	// roll
	g_signal_connect(enter_button[0], "clicked", G_CALLBACK(enterA), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[0], Width * 1 / 3 - 50, 50);
	gtk_fixed_put(GTK_FIXED(fix), input[0], Width * 1 / 3 - 50, 100);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[0], Width * 1 / 3 - 50, 150);
	g_signal_connect(enter_button[1], "clicked", G_CALLBACK(enterX), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[1], Width * 1 / 3 - 50, Height / 3);
	gtk_fixed_put(GTK_FIXED(fix), input[1], Width * 1 / 3 - 50, Height / 3 + 50);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[1], Width * 1 / 3 - 50, Height / 3 + 100);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	// quit_again();
	return;
}
static void AdX_roll(GtkApplication *app, gpointer data)
{
	enterA();
	enterX();
	if (set[0] == 0 || set[1] == 0)
	{
		input_label[9] = gtk_label_new("Please enter A and X.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[9], Width * 1 / 3 - 50, Height - 100);
		gtk_widget_show_all(window);
		return;
	}
	clear_all_button();
	fix = gtk_fixed_new();
	char final[100];
	result_init();
	label = gtk_label_new("AdX result:");
	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		result[i] = dice(inp_num[1]);
		sprintf(dice_num, "%d", result[i]);
		dices[i] = gtk_button_new_with_label(dice_num);
		gtk_fixed_put(GTK_FIXED(fix), dices[i], 75 * i + 100, Height / 3);
	}
	int32_t sum = 0;
	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		sum += result[i];
	}
	sprintf(final, "%d d %d result: %d", inp_num[0], inp_num[1], sum);
	final_label = gtk_label_new(final);
	gtk_fixed_put(GTK_FIXED(fix), label, Width / 2 - 50, Height * 1 / 3 - 100);
	gtk_fixed_put(GTK_FIXED(fix), final_label, Width * 1 / 3 - 50, Height * 2 / 3);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	quit_again();
	return;
}
static void AdXkY_add_B_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	set_init();
	fix = gtk_fixed_new();
	input_label[0] = gtk_label_new("Enter A:");
	input[0] = gtk_entry_new();
	enter_button[0] = gtk_button_new_with_label("Enter");
	input_label[1] = gtk_label_new("Enter X:");
	input[1] = gtk_entry_new();
	enter_button[1] = gtk_button_new_with_label("Enter");
	input_label[2] = gtk_label_new("Enter Y:");
	input[2] = gtk_entry_new();
	enter_button[2] = gtk_button_new_with_label("Enter");
	input_label[3] = gtk_label_new("Enter B:");
	input[3] = gtk_entry_new();
	enter_button[3] = gtk_button_new_with_label("Enter");
	// roll
	enter_button[9] = gtk_button_new_with_label("Roll");
	g_signal_connect(enter_button[9], "clicked", G_CALLBACK(AdXkY_add_B_roll), NULL);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[9], Width / 2 - 50, Height - 50);
	// roll
	g_signal_connect(enter_button[0], "clicked", G_CALLBACK(enterA), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[0], Width / 3 - 50, 50);
	gtk_fixed_put(GTK_FIXED(fix), input[0], Width / 3 - 50, 100);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[0], Width / 3 - 50, 150);
	g_signal_connect(enter_button[1], "clicked", G_CALLBACK(enterX), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[1], Width / 3 - 50, Height / 3);
	gtk_fixed_put(GTK_FIXED(fix), input[1], Width / 3 - 50, Height / 3 + 50);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[1], Width / 3 - 50, Height / 3 + 100);
	g_signal_connect(enter_button[2], "clicked", G_CALLBACK(enterY), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[2], Width / 3 - 50, Height * 2 / 3 - 50);
	gtk_fixed_put(GTK_FIXED(fix), input[2], Width / 3 - 50, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[2], Width / 3 - 50, Height * 2 / 3 + 50);
	g_signal_connect(enter_button[3], "clicked", G_CALLBACK(enterB), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[3], Width * 2 / 3 - 50, Height * 2 / 3 - 50);
	gtk_fixed_put(GTK_FIXED(fix), input[3], Width * 2 / 3 - 50, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[3], Width * 2 / 3 - 50, Height * 2 / 3 + 50);

	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	return;
}
static void AdXkY_add_B_roll(GtkApplication *app, gpointer data)
{
	num_choose = 0;
	enterA();
	enterX();
	enterY();
	enterB();
	if (set[0] == 0 || set[1] == 0 || set[2] == 0 || set[3] == 0)
	{
		input_label[9] = gtk_label_new("Please enter A, X, Y and B.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[9], Width / 2 - 50, Height - 100);
		gtk_widget_show_all(window);
		return;
	}
	clear_all_button();
	fix = gtk_fixed_new();
	result_init();
	char choose[100];
	sprintf(choose, "Click to discard %d dice:", inp_num[0] - inp_num[2]);
	label = gtk_label_new(choose);
	if (inp_num[2] == inp_num[0])
	{
		static int32_t zero = 0;
		dices[0] = gtk_button_new_with_label("OK");
		g_signal_connect(dices[0], "clicked", G_CALLBACK(AdXkY_add_B_count), &zero);
		g_signal_connect_swapped(dices[0], "clicked", G_CALLBACK(gtk_widget_destroy), dices[0]);
		gtk_fixed_put(GTK_FIXED(fix), dices[0], Width / 2 - 50, Height * 2 / 3);
	}

	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		result[i] = dice(inp_num[1]);
		sprintf(dice_num, "%d", result[i]);
		dices[i] = gtk_button_new_with_label(dice_num);
		gtk_fixed_put(GTK_FIXED(fix), dices[i], 75 * i + 100, Height / 3);
		if (inp_num[2] != inp_num[0])
		{
			g_signal_connect(dices[i], "clicked", G_CALLBACK(AdXkY_add_B_count), &result[i]);
			g_signal_connect_swapped(dices[i], "clicked", G_CALLBACK(gtk_widget_destroy), dices[i]);
		}
	}

	gtk_fixed_put(GTK_FIXED(fix), label, Width / 2 - 50, Height * 1 / 3 - 100);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	return;
}
static void AdXkY_add_B_count(GtkApplication *app, gpointer data)
{
	int32_t *inp_data = (int32_t *)data;
	char final[100];
	if (num_choose < inp_num[0] - inp_num[2] - 1)
	{
		num_choose++;
		discard += *inp_data;
		return;
	}
	else
	{
		discard += *inp_data;
		int32_t sum = 0;
		for (int32_t i = 0; i < inp_num[0]; i++)
		{
			// if (dices[i] != NULL)
			sum += result[i];
		}
		sum -= discard;
		discard = 0;
		sprintf(final, "%d d %d k %d + %d result: %d", inp_num[0], inp_num[1], inp_num[2], inp_num[3], sum + inp_num[3]);
		final_label = gtk_label_new(final);
		gtk_fixed_put(GTK_FIXED(fix), final_label, Width * 1 / 3 - 50, Height * 2 / 3);
		gtk_widget_show_all(window);
		quit_again();
	}
	return;
}
static void AdXkhHklLkcC_add_B_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	set_init();
	fix = gtk_fixed_new();
	input_label[0] = gtk_label_new("Enter A:");
	input[0] = gtk_entry_new();
	enter_button[0] = gtk_button_new_with_label("Enter");
	input_label[1] = gtk_label_new("Enter X:");
	input[1] = gtk_entry_new();
	enter_button[1] = gtk_button_new_with_label("Enter");
	input_label[2] = gtk_label_new("Enter C:");
	input[2] = gtk_entry_new();
	enter_button[2] = gtk_button_new_with_label("Enter");
	input_label[3] = gtk_label_new("Enter B:");
	input[3] = gtk_entry_new();
	enter_button[3] = gtk_button_new_with_label("Enter");
	input_label[4] = gtk_label_new("Enter H:");
	input[4] = gtk_entry_new();
	enter_button[4] = gtk_button_new_with_label("Enter");
	input_label[5] = gtk_label_new("Enter L:");
	input[5] = gtk_entry_new();
	enter_button[5] = gtk_button_new_with_label("Enter");

	// roll
	enter_button[9] = gtk_button_new_with_label("Roll");
	g_signal_connect(enter_button[9], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B_roll), NULL);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[9], Width / 2 - 50, Height - 50);
	// roll
	g_signal_connect(enter_button[0], "clicked", G_CALLBACK(enterA), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[0], Width / 3 - 50, 50);
	gtk_fixed_put(GTK_FIXED(fix), input[0], Width / 3 - 50, 100);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[0], Width / 3 - 50, 150);
	g_signal_connect(enter_button[1], "clicked", G_CALLBACK(enterX), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[1], Width / 3 - 50, Height / 3);
	gtk_fixed_put(GTK_FIXED(fix), input[1], Width / 3 - 50, Height / 3 + 50);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[1], Width / 3 - 50, Height / 3 + 100);
	g_signal_connect(enter_button[2], "clicked", G_CALLBACK(enterC), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[2], Width / 3 - 50, Height * 2 / 3 - 50);
	gtk_fixed_put(GTK_FIXED(fix), input[2], Width / 3 - 50, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[2], Width / 3 - 50, Height * 2 / 3 + 50);
	g_signal_connect(enter_button[3], "clicked", G_CALLBACK(enterB), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[3], Width * 2 / 3 - 50, Height * 2 / 3 - 50);
	gtk_fixed_put(GTK_FIXED(fix), input[3], Width * 2 / 3 - 50, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[3], Width * 2 / 3 - 50, Height * 2 / 3 + 50);
	g_signal_connect(enter_button[4], "clicked", G_CALLBACK(enterH), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[4], Width * 2 / 3 - 50, 50);
	gtk_fixed_put(GTK_FIXED(fix), input[4], Width * 2 / 3 - 50, 100);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[4], Width * 2 / 3 - 50, 150);
	g_signal_connect(enter_button[5], "clicked", G_CALLBACK(enterL), NULL);
	gtk_fixed_put(GTK_FIXED(fix), input_label[5], Width * 2 / 3 - 50, Height / 3);
	gtk_fixed_put(GTK_FIXED(fix), input[5], Width * 2 / 3 - 50, Height / 3 + 50);
	gtk_fixed_put(GTK_FIXED(fix), enter_button[5], Width * 2 / 3 - 50, Height / 3 + 100);

	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	return;
}

static void AdXkhHklLkcC_add_B_roll(GtkApplication *app, gpointer data)
{
	enterA();
	enterX();
	enterH();
	enterL();
	enterC();
	enterB();
	discard=0;
	if (set[0] == 0 || set[1] == 0 || set[2] == 0 || set[3] == 0 || set[4] == 0 || set[5] == 0)
	{
		input_label[9] = gtk_label_new("Please enter A, X, C, B, H and L.");
		gtk_fixed_put(GTK_FIXED(fix), input_label[9], Width / 2 - 50, Height - 100);
		gtk_widget_show_all(window);
		return;
	}
	result_init();
	num_choose = 0;
	char choose[100];
	clear_all_button();
	fix = gtk_fixed_new();
	int32_t sort[10] = {0};
	sprintf(choose, "%d d %d result:", inp_num[0], inp_num[1]);
	show_label[0] = gtk_label_new(choose);
	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		result[i] = dice(inp_num[1]);
		sprintf(dice_num, "%d", result[i]);
		dices[i] = gtk_button_new_with_label(dice_num);
		gtk_fixed_put(GTK_FIXED(fix), dices[i], 75 * i + 100, 50);
	}
	gtk_fixed_put(GTK_FIXED(fix), show_label[0], Width / 2 - 50, 0);
	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		sort[i] = result[i];
	}
	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		for (int32_t j = 0; j < inp_num[0]; j++)
		{
			if (sort[i] > sort[j])
			{
				int32_t temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
	sprintf(choose, "Highest %d:", inp_num[4]);
	show_label[1] = gtk_label_new(choose);
	for (int32_t i = 0; i < inp_num[4]; i++)
	{

		sprintf(dice_num, "%d", sort[i]);
		dices[i] = gtk_button_new_with_label(dice_num);
		gtk_fixed_put(GTK_FIXED(fix), dices[i], 75 * i + 100, Height / 3);
	}
	sprintf(choose, "Lowest %d:", inp_num[5]);
	show_label[2] = gtk_label_new(choose);
	for (int32_t i = 0; i < inp_num[5]; i++)
	{
		sprintf(dice_num, "%d", sort[inp_num[0] - 1 - i]);
		dices[i] = gtk_button_new_with_label(dice_num);
		gtk_fixed_put(GTK_FIXED(fix), dices[i], 75 * i + 100, Height / 3 + 100);
	}
	gtk_fixed_put(GTK_FIXED(fix), show_label[1], Width / 2 - 50, Height / 3 - 100);
	gtk_fixed_put(GTK_FIXED(fix), show_label[2], Width / 2 - 50, Height / 3 + 50);
	for (int32_t i = 0; i < 10; i++)
	{
		remain[i] = result[i];
	}
	for (int32_t i = 0; i < inp_num[4]; i++)
	{
		for (int32_t j = 0; j < inp_num[0]; j++)
		{
			if (remain[j] == sort[i])
			{
				remain[j] = 0;
				break;
			}
		}
	}
	for (int32_t i = 0; i < inp_num[5]; i++)
	{
		for (int32_t j = 0; j < inp_num[0]; j++)
		{
			if (remain[j] == sort[inp_num[0] - 1 - i])
			{
				remain[j] = 0;
				break;
			}
		}
	}
	int32_t rm = 0;
	for (int32_t i = 0; i < inp_num[0]; i++)
	{
		if (remain[i] == 0 && rm < inp_num[4] + inp_num[5])
		{

			rm++;
			for (int32_t j = i; j < inp_num[0] - 1; j++)
			{
				remain[j] = remain[j + 1];
			}
			remain[inp_num[0] - rm] = 0;
			i--;
		}
	}
	sprintf(choose, "Please choose %d dices to discard:", inp_num[0] - inp_num[4] - inp_num[5] - inp_num[2]);
	show_label[3] = gtk_label_new(choose);
	for (int32_t i = 0; i < inp_num[0] - inp_num[4] - inp_num[5]; i++)
	{
		sprintf(dice_num, "%d", remain[i]);
		dices[i] = gtk_button_new_with_label(dice_num);
		g_signal_connect(dices[i], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B_count), &remain[i]);
		g_signal_connect_swapped(dices[i], "clicked", G_CALLBACK(gtk_widget_destroy), dices[i]);
		gtk_fixed_put(GTK_FIXED(fix), dices[i], 75 * i + 100, Height * 2 / 3);
	}
	if (inp_num[0] - inp_num[4] - inp_num[5] - inp_num[2] == 0)
	{
		static int32_t zero = 0;
		dices[0] = gtk_button_new_with_label("OK");
		g_signal_connect(dices[0], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B_count), &zero);
		g_signal_connect_swapped(dices[0], "clicked", G_CALLBACK(gtk_widget_destroy), dices[0]);
		gtk_fixed_put(GTK_FIXED(fix), dices[0], Width / 2 - 50, Height * 2 / 3);
	}
	gtk_fixed_put(GTK_FIXED(fix), show_label[3], Width / 2 - 50, Height * 2 / 3 - 50);

	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
	return;
}
static void AdXkhHklLkcC_add_B_count(GtkApplication *app, gpointer data)
{
	int32_t *inp_data = (int32_t *)data;
	char final[100];
	if (num_choose < inp_num[0] - inp_num[4] - inp_num[5] - inp_num[2] - 1)
	{
		num_choose++;
		discard += *inp_data;
		return;
	}
	else
	{
		discard += *inp_data;
		int32_t sum = 0;
		for (int32_t i = 0; i < inp_num[0]; i++)
		{
			// if (dices[i] != NULL)
			sum += result[i];
		}
		sum -= discard;
		discard = 0;
		sum -= inp_num[3];
		sprintf(final, "%d d %d kh %d kl %d kc %d + %d result: %d", inp_num[0], inp_num[1], inp_num[4], inp_num[5], inp_num[2], inp_num[3], sum);
		final_label = gtk_label_new(final);
		gtk_fixed_put(GTK_FIXED(fix), final_label, Width * 1 / 3 - 50, Height * 2 / 3 + 50);
		gtk_widget_show_all(window);
		quit_again();
	}
	return;
}