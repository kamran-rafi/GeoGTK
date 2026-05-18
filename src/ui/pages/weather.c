/*
 * Handle's all the GUI for Showing weather data inside this page.
*/

#include <gtk/gtk.h>
#include "../components/components.h"
#include "../../utils/logger.h"
#include "gtk/gtkshortcut.h"
#include "../ui.h"
#include "../components/components.h"


/*
 * [TODO] This callback function is used to search for weather location.
*/
void search_location(GtkWidget* widget, gpointer input){
    GtkEntryBuffer* buffer = gtk_entry_get_buffer(input);
    const char* text =  gtk_entry_buffer_get_text(buffer);
    log_info("Searching Location: %s", text);
}

/*
 * Render current location and temperature.
*/
GtkWidget* current_location_temperature(){
    log_debug("Rendering current location and temperature...");

    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, SPACE);
    gtk_widget_set_hexpand(root, TRUE);

    // Location and Temperature are shown in vertical widgets on left side.
    GtkWidget* locationAndTempratureContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* location = gtk_label_new("Arifwala, Pk");
    gtk_widget_add_css_class(location, "current-location");
    GtkWidget* temperature = gtk_label_new("36°C");
    gtk_widget_add_css_class(temperature, "current-temperature");
    gtk_label_set_xalign(GTK_LABEL(temperature), 0.0);
    gtk_box_append(GTK_BOX(locationAndTempratureContainer), location);
    gtk_box_append(GTK_BOX(locationAndTempratureContainer), temperature);

    // Icon is shown on right side.
    GtkWidget* icon = get_icon("/home/kamran/Projects/GeoGTK/src/assets/placeholder.svg", 88);
    gtk_widget_set_halign(icon, GTK_ALIGN_END);
    gtk_widget_set_hexpand(icon, TRUE);
    gtk_widget_add_css_class(icon, "current-weather-icon");

    gtk_box_append(GTK_BOX(root), locationAndTempratureContainer);
    gtk_box_append(GTK_BOX(root), icon);

    return root;
}

/*
 * Creates and returns a weather condition Item to be shown inside the current_condtion() container.
*/
GtkWidget* current_condition_item(const char* title,const char* text){
    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACE/2 /* Half space compared to make spacing. */);
    gtk_widget_add_css_class(root, "current-condition-item");
    gtk_widget_set_hexpand(root, TRUE);

    GtkWidget* icon = get_icon("/home/kamran/Projects/GeoGTK/src/assets/placeholder.svg", 42);
    gtk_widget_add_css_class(icon, "current-condition-item-icon");

    GtkWidget* type = gtk_label_new(title);
    gtk_widget_add_css_class(type, "current-condition-item-type");

    GtkWidget* data = gtk_label_new(text);
    gtk_widget_add_css_class(data, "current-condition-item-data");

    gtk_box_append(GTK_BOX(root), icon);
    gtk_box_append(GTK_BOX(root), type);
    gtk_box_append(GTK_BOX(root), data);

    return root;
}

/*
 * Renders widgets inside a container to show current weather condition.
*/
GtkWidget* current_condition(){

    log_debug("Rendering current condition...");

    GtkWidget* root = gtk_grid_new();
    gtk_widget_set_hexpand(root, TRUE);
    gtk_widget_add_css_class(root, "current-condition-container");

    // Grid, Child, Col, Row, Col-Span, Row-Span
    gtk_grid_attach(GTK_GRID(root), current_condition_item("Wind", "7.6 KM/h"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(root), current_condition_item("Humidity", "48%"), 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(root), current_condition_item("Visibility", "5.0 KM"), 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(root), current_condition_item("UV Index", "0.0"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(root), current_condition_item("Precipitation", "0.0 in"), 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(root), current_condition_item("Clouds", "0"), 2, 1, 1, 1);

    return root;
}

GtkWidget* display_weather(){
    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACE);
    gtk_widget_set_hexpand(root, TRUE);

    gtk_box_append(GTK_BOX(root), current_location_temperature());
    gtk_box_append(GTK_BOX(root), current_condition());

    return root;
}

/*
 * Todos: 
 * 1- [DONE] Add a Location Search Input.
 * 2- [DONE] Add Current Weather Temperature and Location Info.
 * 3- [DONE] Add current Weather Condition Container.
 * 4- [PENDING] Add Hourly Weather Forcast Container. 
 * 5- [PENDING] Add Daily Weather Forcast Container.
*/
GtkWidget* weather_page(){
    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Appended input widget to search for location.
    gtk_box_append(GTK_BOX(root), read_input("Search location...", "Search", search_location));
    gtk_box_append(GTK_BOX(root), display_weather());

    return root;
}