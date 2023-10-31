#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>

#define TITLE "DICE ROLLS"
#define Width 900
#define Height 600
// this program is edit ver of https://docs.gtk.org/gtk3/getting_started.html
GtkWidget *window;
GtkWidget *button[11];
GtkWidget *fix;

static void clear_all_button(/*GtkApplication *app, gpointer data*/);
static void start_game(GtkApplication *app, gpointer data);
static void choose_game(GtkApplication *app, gpointer data);
static void Id6(GtkApplication *app, gpointer data);
static void AdX(GtkApplication *app, gpointer data);
static void AdXkY_add_B(GtkApplication *app, gpointer data);
static void AdXkhHklLkcC_add_B(GtkApplication *app, gpointer data);

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("darrin.s.Game", G_APPLICATION_DEFAULT_FLAGS);//G_APPLICATION_FLAGS_NONE
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
	button[0] = gtk_button_new_with_label("1d6");
	g_signal_connect(button[0], "clicked", G_CALLBACK(Id6), NULL);
	button[1] = gtk_button_new_with_label("AdX");
	g_signal_connect(button[1], "clicked", G_CALLBACK(AdX), NULL);
	button[2] = gtk_button_new_with_label("AdXkY+B");
	g_signal_connect(button[2], "clicked", G_CALLBACK(AdXkY_add_B), NULL);
	button[3] = gtk_button_new_with_label("AdXkhHklLkcC+B");
	g_signal_connect(button[3], "clicked", G_CALLBACK(AdXkhHklLkcC_add_B), NULL);
	button[4] = gtk_button_new_with_label("Press here to quit.");
	g_signal_connect(button[4], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_fixed_put(GTK_FIXED(fix), button[0], Width / 2-400,Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[1], Width / 2-200, Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[2], Width / 2, Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[3], Width / 2+200, Height*2/3);
	gtk_fixed_put(GTK_FIXED(fix), button[4], Width / 2-100, Height*2/3+100);
	gtk_container_add(GTK_CONTAINER(window), fix);
	gtk_widget_show_all(window);
}

static void Id6(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	
	gtk_widget_show_all(window);
}
static void AdX(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	gtk_widget_show_all(window);
}
static void AdXkY_add_B(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	gtk_widget_show_all(window);
}
static void AdXkhHklLkcC_add_B(GtkApplication *app, gpointer data)
{
	clear_all_button();
	fix = gtk_fixed_new();
	gtk_widget_show_all(window);
}