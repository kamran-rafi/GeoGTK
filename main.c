#include <gtk/gtk.h>

/**************
* HELLO WORLD *
**************/

// An event handler for GTK app must have these two params.
void greet(GtkWidget* widget, gpointer data){
    g_print("Welcome, %s!\n", (char*)data);
}

// An event handler for closing application.
void destroy(GtkWidget* widget, gpointer data){
    g_print("CLEANING UP...");
}

// This is our function where GUI of our application is initialized.
static void activate(GtkApplication *app, gpointer user_data){
    /*
     * Initialization of our main window with some style and info.
    */
    GtkWidget* window = gtk_application_window_new(app);
    gtk_window_set_title (GTK_WINDOW (window), "Weather");
    gtk_window_set_default_size (GTK_WINDOW (window), 240, 320);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), nullptr);

    /*
     * Initialization of our button with click handler.
    */
    GtkWidget* button = gtk_button_new_with_label("Click Me");
    g_signal_connect(button, "clicked", G_CALLBACK(greet), "Kamran");
    // Bit styling for button.
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(button, GTK_ALIGN_CENTER);

    // Add button to our main window.
    gtk_window_set_child(GTK_WINDOW(window), button);

    // Display our window.
    gtk_window_present(GTK_WINDOW (window));
}

int main (int argc, char *argv[])
{
    /*
     * Create a new application using gtk_application_new(String, FLAGS)
     * which returns a pointer to our GTK Application.
    */
    GtkApplication *app = gtk_application_new("weather.sudo.sama", G_APPLICATION_DEFAULT_FLAGS);
    // Now we will activate our application and attach widgets to it.
    g_signal_connect(app, "activate", G_CALLBACK(activate), nullptr);

    /*
     * Now we run our application and after application run
     * is finished a status code of int is returned.
    */
    int status = g_application_run(G_APPLICATION(app), argc, argv);

    // Clear up memory of our application.
    g_object_unref(app);

    return status;
}
