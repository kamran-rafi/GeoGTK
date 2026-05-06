#include <gtk/gtk.h>
#include "utils/logger.h"

/**************
* HELLO WORLD *
**************/

// An event handler for GTK app must have these two params.
void greet(GtkWidget* widget, gpointer data){
    g_print("Welcome, %s!\n", (char*)data);
}

// An event handler for closing application.
void destroy(GtkWindow* window, gpointer data){
    info("Destroying window...");
    gtk_window_close(window);
}

void quit(GtkWidget* widget, gpointer window){
    gtk_window_close(window);
}

void save(GtkWidget* widget, gpointer input){

    GtkEntryBuffer* buffer = gtk_entry_get_buffer(input);

    info(gtk_entry_buffer_get_text(buffer));
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
     * Creating a centered aligned Container "Box"
    */
    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    // Bit styling for box.
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

    /*
     * Initialization of our button with click handler.
    */
    GtkWidget* button = gtk_button_new_with_label("Click Me");
    g_signal_connect(button, "clicked", G_CALLBACK(greet), "Kamran");

    GtkWidget* quitBtn = gtk_button_new_with_label("Quit");
    g_signal_connect(quitBtn, "clicked", G_CALLBACK(quit), window);

    // Add buttons to our box widget.
    gtk_box_append(GTK_BOX(box), button);
    gtk_box_append(GTK_BOX(box), quitBtn);

    // GtkEntryBuffer* inputBuffer = gtk_entry_buffer_new("Hello, Input Buffer!", 20);

    // g_print("%s",gtk_entry_buffer_get_text(inputBuffer));

    GtkWidget* input = gtk_entry_new();

    //* inputBuffer = gtk_entry_get_buffer(input);

    gtk_box_append(GTK_BOX(box), input);

    GtkWidget* btnSave = gtk_button_new_with_label("Save");
    g_signal_connect(btnSave, "clicked", G_CALLBACK(save), input);

    gtk_box_append(GTK_BOX(box), btnSave);

    gtk_window_set_child(GTK_WINDOW(window), box);

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
