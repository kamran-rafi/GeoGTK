/*
 * This file contains UI for searching and showing weather.
*/
#include <gtk/gtk.h>
#include "../utils/constants.h"

// Takes Icon path and size of icon and returns a gtk image widget.
GtkWidget* get_parsed_svg_icon(char* icPath, int icSize){
    GdkTexture* tex = gdk_texture_new_from_filename(
        (char*)icPath,
        NULL
    );
    GtkWidget* icon = gtk_image_new_from_paintable(GDK_PAINTABLE(tex));
    gtk_image_set_pixel_size(GTK_IMAGE(icon), icSize);
    gtk_widget_set_halign(icon, GTK_ALIGN_END);
    gtk_widget_set_hexpand(icon, TRUE);
    return icon;
}

// This widget is used for searching cities.
GtkWidget* search_input(){
    GtkWidget* input = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(input), "Search city...");
    gtk_widget_add_css_class(input, "search-input");
    return input;
}

// Renders Location, current temperation and approperiate icon.
GtkWidget* today_weather_current(){
    GtkWidget* currentWeatherContainer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, PADDING);
    gtk_widget_set_hexpand(currentWeatherContainer, TRUE);

    GtkWidget* locationAndTempratureContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);

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
    GtkWidget* icon = get_parsed_svg_icon("/home/kamran/Projects/Weather/assets/placeholder.svg", 128);
    gtk_widget_add_css_class(icon, "current-weather-icon");
    // END: Icon Widget

    gtk_box_append(GTK_BOX(locationAndTempratureContainer), location);
    gtk_box_append(GTK_BOX(locationAndTempratureContainer), temperature);

    gtk_box_append(GTK_BOX(currentWeatherContainer), locationAndTempratureContainer);
    gtk_box_append(GTK_BOX(currentWeatherContainer), icon);

    return currentWeatherContainer;
}

// Todo!!!!!!!!!!
GtkWidget* today_weather_condition(){
    GtkWidget* weatherConditionContainer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, PADDING);
    gtk_widget_set_hexpand(weatherConditionContainer, TRUE);
    gtk_widget_add_css_class(weatherConditionContainer, "today-weather-condition");

    return weatherConditionContainer;
}

// Todo!!!!!!!!!!
GtkWidget* today_weather_hourly(){
    GtkWidget* hourlyWeatherContainer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, PADDING);
    gtk_widget_set_hexpand(hourlyWeatherContainer, TRUE);
    gtk_widget_set_vexpand(hourlyWeatherContainer, TRUE);
    gtk_widget_add_css_class(hourlyWeatherContainer, "today-weather-hourly");

    return hourlyWeatherContainer;
}

// ToDo:
// 1: Add today current weather: DONE
// 2: Add today weather condition: PENDING
// 3: Add today hourly forecast: PENDING
GtkWidget* today_weather(){
    GtkWidget* todayWeatherContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);
    gtk_widget_set_hexpand(todayWeatherContainer, TRUE);
    gtk_widget_add_css_class(todayWeatherContainer, "today-weather-container");

    gtk_box_append(GTK_BOX(todayWeatherContainer), today_weather_current());
    gtk_box_append(GTK_BOX(todayWeatherContainer), today_weather_condition());
    gtk_box_append(GTK_BOX(todayWeatherContainer), today_weather_hourly());

    return todayWeatherContainer;
}

// ToDo:
// 1: Add a daily forecast: PENDING
GtkWidget* daily_weather(){
    GtkWidget* dailyWeatherContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);
    gtk_widget_set_hexpand(dailyWeatherContainer, TRUE);
    gtk_widget_set_vexpand(dailyWeatherContainer, TRUE);
    gtk_widget_add_css_class(dailyWeatherContainer, "daily-weather-container");

    return dailyWeatherContainer;
}

GtkWidget* weather_container(){
    // This is Root Weather Container and all the weather UI is rendered inside of it.
    GtkWidget* rootContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_hexpand(rootContainer, TRUE); // Takes all the avaiable horizontal space.
    gtk_widget_add_css_class(rootContainer, "root-weather-container"); // Attach CSS class.

    /*
     * This container will contain two sub containers.
     * LEFT:    Contains today's weather.
     * RIGHT:   Contains daily weather.
    */
    GtkWidget* weatherDataContainer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, PADDING);
    gtk_widget_set_hexpand(weatherDataContainer, TRUE);
    // Appending left child. today weather
    gtk_box_append(GTK_BOX(weatherDataContainer), today_weather());
    // Appending right child. daily weather
    gtk_box_append(GTK_BOX(weatherDataContainer), daily_weather());

    // Attach a Location search bar to Root container.
    gtk_box_append(GTK_BOX(rootContainer), search_input());
    // Attack weather info data to root container.
    gtk_box_append(GTK_BOX(rootContainer), weatherDataContainer);

    return rootContainer;
}
