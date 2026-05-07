#include <gtk/gtk.h>
#include "utils/logger.h"
#include "utils/constants.h"
#include "widgets/widgets.h"

// An event handler for closing application.
void destroy(GtkWindow* window, gpointer data){
    info("Destroying window...");
    gtk_window_close(window);
}

// Call it to apply styles to our styling to User Interface.
void load_style(){
    GtkCssProvider* provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "/home/kamran/Projects/Weather/styles/global.css");
    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
}

// Builds UI and displays windows on screen.
void activate(GtkApplication* weatherApp){
    // Creating a main window which contains our widgets for interaction.
    GtkWidget* window = gtk_application_window_new(weatherApp);
    /*
     * Setting some default styling for window.
    */
    gtk_window_set_title(GTK_WINDOW(window), "WeatherGTK");
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
    load_style();
    // Window close handler...
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), nullptr);

    // This is our main box and everything all the intractive elements would be inside it.
    GtkWidget* hBoxMain = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
    gtk_widget_add_css_class(hBoxMain, "main-container");
    gtk_widget_set_hexpand(hBoxMain, TRUE);

    gtk_box_append(GTK_BOX(hBoxMain), toolbar_container());
    gtk_box_append(GTK_BOX(hBoxMain), weather_container());

    gtk_window_set_child(GTK_WINDOW(window), hBoxMain);
    // Display the window.
    gtk_window_present(GTK_WINDOW(window));
}

int main (int argc, char *argv[])
{
    /*
     * Create a new application using gtk_application_new(String, FLAGS).
    */
    GtkApplication* weatherApp = gtk_application_new("weather.sudo.sama", G_APPLICATION_DEFAULT_FLAGS);

    // Now we will activate our application and attach widgets to it.
    g_signal_connect(weatherApp, "activate", G_CALLBACK(activate), nullptr);

    /*
     * Start Application after full setup.
     * Once finished a status code is returned indicating Success "0" or failure.
    */
    int status = g_application_run(G_APPLICATION(weatherApp), argc, argv);

    // Clear up memory of our application.
    g_object_unref(weatherApp);

    return status;
}
