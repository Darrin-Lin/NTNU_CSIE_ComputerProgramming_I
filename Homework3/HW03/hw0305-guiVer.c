#include "diceRolls.h"
#include <stdio.h>
#include <stdint.h>
#include <gtk/gtk.h>

#define TITLE "DICE ROLLS"


int main(int argc, char *argv[])
{
	//some from wikipedia https://zh.wikipedia.org/zh-tw/GTK
	GtkWidget *window;
	GtkWidget *label;
	gtk_init (&argc, &argv);
	//create the main, top level, window
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	//give it the title
	gtk_window_set_title (GTK_WINDOW (window), TITLE);
	// Connect the destroy signal of the window to gtk_main_quit
	// When the window is about to be destroyed we get a notification and
	// stop the main GTK loop

	g_signal_connect (window, "destroy",
					  G_CALLBACK (gtk_main_quit), NULL);
	//Create the "Hello, World" label
	char num[10];
	sptf(num, "%d", 1);
	label = gtk_label_new (num);
	//and insert it into the main window
	gtk_container_add (GTK_CONTAINER (window), label);
	//make sure that everything, window and label, are visible
	gtk_widget_show_all (window);
	// start the main loop, and let it rest there until the application is closed
	gtk_main ();
	
	
	return 0;
}
