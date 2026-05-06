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

GtkWidget* today_weather_container(){
    // All containers of today weather goes inside main container in a Column Fashion
    GtkWidget* mainContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);

    // This container will contain location, temperature and an icon.
    GtkWidget* hContainer1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, PADDING);
    gtk_widget_add_css_class(hContainer1, "h-container-one");
    // This container will contain location and temperature to left side.
    GtkWidget* vContainer1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);

    // START: Location Widget
    GtkWidget* location = gtk_label_new("Arifwala, Pk");
    gtk_widget_add_css_class(location, "current-weather-location");
    // END: Location Widget

    // START: Temperature Widget
    GtkWidget* temperature = gtk_label_new("36°C");
    gtk_widget_add_css_class(temperature, "current-weather-temperature");
    gtk_label_set_xalign(GTK_LABEL(temperature), 0.0);
    // END: Temperature Widget

    // START: Icon Widget
    GdkTexture* tex = gdk_texture_new_from_filename(
        "/home/kamran/Projects/Weather/assets/placeholder.svg",
        NULL
    );
    GtkWidget* icon = gtk_image_new_from_paintable(GDK_PAINTABLE(tex));
    gtk_image_set_pixel_size(GTK_IMAGE(icon), 128);
    gtk_widget_set_halign(icon, GTK_ALIGN_END);
    gtk_widget_set_hexpand(icon, TRUE);
    gtk_widget_add_css_class(icon, "current-weather-icon");
    // END: Icon Widget

    gtk_box_append(GTK_BOX(vContainer1), location);
    gtk_box_append(GTK_BOX(vContainer1), temperature);

    gtk_box_append(GTK_BOX(hContainer1), vContainer1);
    gtk_box_append(GTK_BOX(hContainer1), icon);

    gtk_box_append(GTK_BOX(mainContainer), hContainer1);
    return mainContainer;
}

GtkWidget* weather_container(){
    GtkWidget* weather = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);

    // Added CSS class name which is accessed inside GTK CSS.
    gtk_widget_add_css_class(weather, "weather-container");
    gtk_widget_set_hexpand(weather, TRUE);

    gtk_box_append(GTK_BOX(weather), search_input());
    gtk_box_append(GTK_BOX(weather), today_weather_container());

    return weather;
}
