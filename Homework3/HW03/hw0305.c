#include "diceRolls.h"
#include <stdio.h>
// #include <gtk/gtk.h>

#define TITLE "DICE ROLLS"
#define ptf printf
#define scf scanf

void rule();

int main(/*int argc, char *argv[]*/)
{
	rule();
	int32_t action = 0;
	ptf("----------------------------------------\n");
	ptf("Your action: ");
	scf("%d", &action);

	while (action)
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
		case -1:
			rule();
			break;
		default:
			ptf("Not an action number!\n");
			goto end;
			break;
		}
		ptf("----------------------------------------\n");
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
	end:;
	ptf("Bye!\n");
	return 0;
}
void rule()
{
	ptf("Welcom to DiceRoller!\n");
	ptf("Input \033[94m0\033[0m to quit.\n");
	ptf("Input \033[94m1\033[0m to roll a dice with \033[33m6\033[0m side.\n");
	ptf("Input \033[94m2\033[0m to roll \033[33mA\033[0m dice with \033[33mX\033[0m sides each.\n");
	ptf("Input \033[94m3\033[0m to roll \033[33mA\033[0m dice with \033[33mX\033[0m sides each, and choose \033[33mY\033[0m dice and add \033[33mB\033[0m for the bonus.\n");
	ptf("Input \033[94m4\033[0m to roll \033[33mA\033[0m dice with \033[33mX\033[0m sides each, keeping the \033[33mH\033[0m highest, the \033[33mL\033[0m lowest, and \033[33mC\033[0m of the player’s choice and add \033[33mB\033[0m for the bonus.\n");
	ptf("Input \033[94m-1\033[0m number to see this again.\n");
	ptf("Input other number will also quit this program.\n");
	ptf("\n1:1d6\n2:AdX\n3:AdXkY+B\n4:AdXkhHklLkcC+B\n");
	ptf("\nrange:\n");
	ptf("\033[33mA\033[0m: 0~10\n");
	ptf("\033[33mX\033[0m: 2~100\n");
	ptf("\033[33mB\033[0m: -10~10\n");
	ptf("\033[33mY\033[0m: 0~A\n");
	ptf("\033[33mH\033[0m: 0~A\n");
	ptf("\033[33mL\033[0m: 0~A\n");
	ptf("\033[33mC\033[0m: 0~A-(L+H)\n");
}