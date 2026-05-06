/*
 * This file contains UI for searching and showing weather.
*/
#include <gtk/gtk.h>
#include "../utils/constants.h"

// This widget is used for searching cities.
GtkWidget* search_input(){
    GtkWidget* input = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(input), "Search city...");
    gtk_widget_add_css_class(input, "search-input");
    return input;
}

GtkWidget* weather_container(){
    GtkWidget* weather = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);

    // Added CSS class name which is accessed inside GTK CSS.
    gtk_widget_add_css_class(weather, "weather-container");
    gtk_widget_set_hexpand(weather, TRUE);

    gtk_box_append(GTK_BOX(weather), search_input());

    return weather;
}
