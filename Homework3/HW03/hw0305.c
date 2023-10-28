#include "diceRolls.h"
#include <stdio.h>
// #include <gtk/gtk.h>

#define TITLE "DICE ROLLS"

int main(/*int argc, char *argv[]*/)
{
    printf("Welcom to DiceRoller!\n");
    printf("Input 0 to quit.\n");
    int32_t action = 0;
    printf("----------------------------------------\n");
    printf("Your action: ");
    scanf("%d", &action);
    
    while (action>=0)
    {
        int32_t result[10] = {0};
        switch (action)
        {
        case 0: // will not active
            goto end;
            break;

        case 1:
            result[0] = dice(6);
            printf("==^==>\n");
            printf("=>%3d>\n", result[0]);
            printf("==v==>\n");
            break;
        default:
            printf("Not an action number!\n");
            break;
        }
        printf("\n----------------------------------------\n");
        printf("Your action: ");
        scanf("%d", &action);
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
    sprintf(num, "%d", 1);
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
printf("Bye!\n");
    return 0;
}