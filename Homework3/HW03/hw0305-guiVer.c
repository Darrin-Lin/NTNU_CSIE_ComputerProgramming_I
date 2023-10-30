#include <gtk/gtk.h>
#include <stdio.h>
#include <stdint.h>

#define TITLE "DICE ROLLS"
#define Wid 900
#define Hei 600
// this program is edit ver of https://docs.gtk.org/gtk3/getting_started.html

static void
clear_window(GtkApplication *app, gpointer data)
{
	for(int i = 0; i < 2; i++)
	{
		GtkWidget *val;
		val=data+i;
		gtk_widget_destroy(val);
		// g_print("data[%d] = %d\n", i, *val);
	}
		
		
}

static void
activate(GtkApplication *app,
		 gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button[10];
	// GtkWidget *box;
	GtkWidget *fix;
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), TITLE);
	gtk_window_set_default_size(GTK_WINDOW(window), Wid, Hei);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	fix = gtk_fixed_new();
	// box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	// gtk_container_add(GTK_CONTAINER(window), box);
	button[0] = gtk_button_new_with_label("Press here to start.");
	g_signal_connect(button[0], "clicked", G_CALLBACK(clear_window), &button);
	// g_signal_connect_swapped(start_button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	// gtk_container_add(GTK_CONTAINER(box), start_button);
	button[1] = gtk_button_new_with_label("Press here to quit.");
	g_signal_connect_swapped(button[1], "clicked", G_CALLBACK(gtk_widget_destroy), window);
	// gtk_container_add(GTK_CONTAINER(box), quit_button);
	gtk_fixed_put(GTK_FIXED(fix), button[0], 300, 300);
	gtk_fixed_put(GTK_FIXED(fix), button[1], 300, 400);
	gtk_container_add(GTK_CONTAINER(window), fix);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}