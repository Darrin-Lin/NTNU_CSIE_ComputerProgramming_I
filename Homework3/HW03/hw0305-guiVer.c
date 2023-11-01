#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"

#define TITLE "Super Dice Bros. - Brawl"
#define Width 800
#define Height 600
#define rule "Welcome to Super Dice Bros. - Brawl!\nThere are also some information in README.\nYou can click the button to choose the action.\nThe actions are:\nClick 1d6 to roll a dice with 6 side.\nClick Adx to roll A dice with X sides each.\nClick AdXkY+B to roll A dice with X sides each, and choose Y dice and add B for the bonus.\nClick AdXkhHklLkcC+B to roll A dice with X sides each, keeping the H highest, the L lowest, and C of the player’s choice and add B for the bonus.\n\nrange:\nA: 0~10\nX: 2~100\nB: -10~10\nY: 0~A\nH: 0~A\nL: 0~A\nC: 0~A-(L+H)"
// this program is edit ver of https://docs.gtk.org/gtk3/getting_started.html
static GtkWidget *window;
static GtkWidget *button[12];
static GtkWidget *fix;
static GtkWidget *label;
static GtkWidget *dices[20];
static GtkWidget *fix_key;
static GtkWidget *entry

	static void clear_all_button(/*GtkApplication *app, gpointer data*/);
static void key();
static void destroy_key();
static void clear_string();
static void start_game(GtkApplication *app, gpointer data);
static void choose_game(GtkApplication *app, gpointer data);
static void Id6_window(GtkApplication *app, gpointer data);
static void AdX_window(GtkApplication *app, gpointer data);
static void AdXkY_add_B_window(GtkApplication *app, gpointer data);
static void AdXkhHklLkcC_add_B_window(GtkApplication *app, gpointer data);

static char dice_num[10];

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	// app = gtk_application_new("darrin.s.Game", G_APPLICATION_FLAGS_NONE);// WSL(Ubuntu) //G_APPLICATION_FLAGS_NONE //EndeavourOS //G_APPLICATION_DEFAULT_FLAGS
	app = gtk_application_new("darrin.s.Game", G_APPLICATION_DEFAULT_FLAGS); // WSL(Ubuntu) //G_APPLICATION_FLAGS_NONE //EndeavourOS //G_APPLICATION_DEFAULT_FLAGS

	g_signal_connect(app, "activate", G_CALLBACK(start_game), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

static void clear_string()
{
	for (int32_t i = 0; i < 10; i++)
	{
		dice_num[i] = '\0';
	}
}

// static void key()
// {

// }

// static void destroy_key()
// {

// }

static void
	clear_all_button(/*GtkApplication *app, gpointer data*/)
{
	// for (int32_t i = 0; i < 11; i++)
	// {
	// 	if (button[i] != NULL)
	// 		gtk_widget_destroy(button[i]);
	// }
	gtk_widget_destroy(fix);
}

static void
start_game(GtkApplication *app,
		   gpointer data)
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
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2 - 100, Height / 2);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2 - 100, Height * 2 / 3);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}

static void choose_game(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	label = gtk_label_new(rule);
	button[0] = gtk_button_new_with_label("1d6");
	g_signal_connect(button[0], "clicked", G_CALLBACK(Id6_window), NULL);
	button[1] = gtk_button_new_with_label("AdX");
	g_signal_connect(button[1] gtk_widget_destroy(fix), "clicked", G_CALLBACK(AdX_window), NULL);
	button[2] = gtk_button_new_with_label("AdXkY+B");
	g_signal_connect(button[2], "clicked", G_CALLBACK(AdXkY_add_B_window), NULL);
	button[3] = gtk_button_new_with_label("AdXkhHklLkcC+B");
	g_signal_connect(button[3], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B_window), NULL);
	button[4] = gtk_button_new_with_label("Press here to quit.");
	g_signal_connect_swapped(button[4], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2 - 400, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2 - 200, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[2], Width / 2, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[3], Width / 2 + 200, Height * 2 / 3);
	gtk_fixed_put(GTK_FIXED(fix), button[4], Width / 2 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), label, 0, 0);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}

static void Id6_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	srand(time(NULL));
	fix = gtk_fixed_new();
	// final = 0;
	int32_t result[10] = {0};
	result[0] = dice(6);
	clear_string();
	sprintf(dice_num, "%d", result[0]);
	label = gtk_label_new("1d6 result:");
	dices[0] = gtk_button_new_with_label(dice_num);
	// quit and again
	button[10] = gtk_button_new_with_label("Press here to quit.");
	button[11] = gtk_button_new_with_label("Play again.");
	g_signal_connect_swapped(button[10], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	g_signal_connect(button[11], "clicked", G_CALLBACK(choose_game), NULL);
	gtk_fixed_put(GTK_FIXED(fix), button[10], Width / 2 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), button[11], Width / 2 + 100, Height * 2 / 3 + 100);
	// quit and again
	gtk_fixed_put(GTK_FIXED(fix), label, Width / 2, Height * 1 / 3 - 100);
	gtk_fixed_put(GTK_FIXED(fix), dices[0], Width / 2, Height * 1 / 3);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}
static void AdX_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	entry = gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table), entry, 1, 2, 2, 3);
	text = gtk_entry_get_text(entry);
	// quit and again
	button[10] = gtk_button_new_with_label("Press here to quit.");
	button[11] = gtk_button_new_with_label("Play again.");
	g_signal_connect_swapped(button[10], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	g_signal_connect(button[11], "clicked", G_CALLBACK(choose_game), NULL);
	gtk_fixed_put(GTK_FIXED(fix), button[10], Width / 2 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), button[11], Width / 2 + 100, Height * 2 / 3 + 100);
	// quit and again
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}
static void AdXkY_add_B_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	// quit and again
	button[10] = gtk_button_new_with_label("Press here to quit.");
	button[11] = gtk_button_new_with_label("Play again.");
	g_signal_connect_swapped(button[10], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	g_signal_connect(button[11], "clicked", G_CALLBACK(choose_game), NULL);
	gtk_fixed_put(GTK_FIXED(fix), button[10], Width / 2 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), button[11], Width / 2 + 100, Height * 2 / 3 + 100);
	// quit and again
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}
static void AdXkhHklLkcC_add_B_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	// quit and again
	button[10] = gtk_button_new_with_label("Press here to quit.");
	button[11] = gtk_button_new_with_label("Play again.");
	g_signal_connect_swapped(button[10], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	g_signal_connect(button[11], "clicked", G_CALLBACK(choose_game), NULL);
	gtk_fixed_put(GTK_FIXED(fix), button[10], Width / 2 - 100, Height * 2 / 3 + 100);
	gtk_fixed_put(GTK_FIXED(fix), button[11], Width / 2 + 100, Height * 2 / 3 + 100);
	// quit and again
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}