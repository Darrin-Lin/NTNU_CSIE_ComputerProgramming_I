#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>
#include "diceRolls.h"

#define TITLE "DICE ROLLS"
#define Width 1000
#define Height 750
#define rule "Welcome to Dice Roller!\nThere are also some information in README.\nYou can input the number to choose the action.\nThe actions are:\nInput 0 to quit.\nInput 1 to roll a dice with 6 side.\nInput 2 to roll A dice with X sides each.\nInput 3 to roll A dice with X sides each, and choose Y dice and add B for the bonus.\nInput 4 to roll A dice with X sides each, keeping the H highest, the L lowest, and C of the player’s choice and add B for the bonus.\nInput -1 number to see this again.\nInput other number will also quit this program.\n\n1:1d6\n2:AdX\n3:AdXkY+B\n4:AdXkhHklLkcC+B\n\nrange:\nA: 0~10\nX: 2~100\nB: -10~10\nY: 0~A\nH: 0~A\nL: 0~A\nC: 0~A-(L+H)"
// this program is edit ver of https://docs.gtk.org/gtk3/getting_started.html
static GtkWidget *window;
static GtkWidget *button[11];
static GtkWidget *fix;
static GtkWidget *label;

static void clear_all_button(/*GtkApplication *app, gpointer data*/);
static void start_game(GtkApplication *app, gpointer data);
static void choose_game(GtkApplication *app, gpointer data);
static void Id6_window(GtkApplication *app, gpointer data);
static void AdX_window(GtkApplication *app, gpointer data);
static void AdXkY_add_B_window(GtkApplication *app, gpointer data);
static void AdXkhHklLkcC_add_B_window(GtkApplication *app, gpointer data);

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("darrin.s.Game", G_APPLICATION_FLAGS_NONE);//GTK3.0//G_APPLICATION_FLAGS_NONE //GTK4.0 G_APPLICATION_DEFAULT_FLAGS
	g_signal_connect(app, "activate", G_CALLBACK(start_game), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

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
	g_signal_connect(button[1], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2-100, Height/2);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2-100, Height*2/3);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}

static void choose_game(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	label = gtk_label_new (rule);
	button[0] = gtk_button_new_with_label("1d6");
	g_signal_connect(button[0], "clicked", G_CALLBACK(Id6_window), NULL);
	button[1] = gtk_button_new_with_label("AdX");
	g_signal_connect(button[1], "clicked", G_CALLBACK(AdX_window), NULL);
	button[2] = gtk_button_new_with_label("AdXkY+B");
	g_signal_connect(button[2], "clicked", G_CALLBACK(AdXkY_add_B_window), NULL);
	button[3] = gtk_button_new_with_label("AdXkhHklLkcC+B");
	g_signal_connect(button[3], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B_window), NULL);
	button[4] = gtk_button_new_with_label("Press here to quit.");
	g_signal_connect(button[4], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2-400,Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2-200, Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[2], Width / 2, Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[3], Width / 2+200, Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[4], Width / 2-100, Height*2/3+100);
	gtk_fixed_put(GTK_FIXED(fix), label, 0, 0);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}

static void Id6_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	// final = 0;
    int32_t result[10] = {0};
    result[0] = dice(6);
	gtk_widget_show_all(window);
}
static void AdX_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	gtk_widget_show_all(window);
}
static void AdXkY_add_B_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	gtk_widget_show_all(window);
}
static void AdXkhHklLkcC_add_B_window(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	gtk_widget_show_all(window);
}