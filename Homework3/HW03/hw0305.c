#include "diceRolls.h"
#include <stdio.h>
// #include <gtk/gtk.h>

#define TITLE "DICE ROLLS"
#define ptf printf
#define scf scanf



int main(/*int argc, char *argv[]*/)
{
	ptf("Welcom to DiceRoller!\n");
	ptf("Input 0 to quit.\n");
	int32_t action = 0;
	ptf("----------------------------------------\n");
	ptf("Your action: ");
	scf("%d", &action);

	while (action >= 0)
	{
		
		switch (action)
		{
		case 0: // will not active
			// goto end;
			break;

		case 1:
			Id6();
			break;
		case 2:
			AdX();
			break;
		case 3:
			AdXkY_add_B();
			break;
		case 4:
			AdXkhHklLkcC_add_B();
			break;
		default:
			ptf("Not an action number!\n");
			break;
		}
		ptf("\n----------------------------------------\n");
		ptf("Your action: ");
		scf("%d", &action);
	}

	/*
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
	g_print("%d",123);
	//make sure that everything, window and label, are visible
	gtk_widget_show_all (window);
	// start the main loop, and let it rest there until the application is closed
	gtk_main ();
	*/
	// end:;
	ptf("Bye!\n");
	return 0;
}