/*
 * This is left side aligned navigation bar.
 * It is used to navigate different pages of app.
 * It highlights current active page.
*/
#include <gtk/gtk.h>
#include "ui.h"
#include "components/components.h"
#include "../app.h"

/*
 * This function toggles the active style for pressed button and removes from previous button.
*/
void toggle_button_focus(GtkWidget* currentButton){
    // Early return if same button is pressed twice.
    if(APP_STATE.prev_focused_button == currentButton) return;

    // Set active style to clicked widget.
    gtk_widget_add_css_class(currentButton, "nav-button-active");

    // If there was a previous button then remove active style from that button.
    if(APP_STATE.prev_focused_button){
        gtk_widget_remove_css_class(APP_STATE.prev_focused_button, "nav-button-active");
    }
    
    // Current currently clicked button as prev button for next toggle handler call.
    APP_STATE.prev_focused_button = currentButton;
}

// Display the weather page inside the page container.
void weather_handler(GtkWidget* widget, gpointer data)
{
    set_page(WEATHER_PAGE);
    toggle_button_focus(widget);
}

// Display the settings page inside the page container.
void settings_handler(GtkWidget* widget, gpointer data){
    set_page(SETTINGS_PAGE);
    toggle_button_focus(widget);
}

/*
 * Returns a custom widget which is used a a button for navigation bar.
 * title: String to give title to button.
 * icPath: String path of icon to show inside the button.
*/
GtkWidget* get_nav_button(const char* title,char* icPath, void (*func)(GtkWidget*, gpointer)){
     GtkWidget* button = gtk_button_new();
     gtk_widget_add_css_class(button, "nav-button");

    GtkWidget* buttonContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACE/2 /*Half the space between childs*/ );

    GtkWidget* icon = get_icon(icPath, 48 /* ICON SIZE */);

    GtkWidget* label = gtk_label_new(title);
    gtk_widget_add_css_class(label, "nav-button-text");

    gtk_box_append(GTK_BOX(buttonContainer), icon);
    gtk_box_append(GTK_BOX(buttonContainer), label);

    gtk_button_set_child(GTK_BUTTON(button), buttonContainer);
    g_signal_connect(button, "clicked", G_CALLBACK(func), NULL);

    return button;
}

/*
 * Todo:
 * 1- Add buttons for different pages.
 * 2- Clicking a button highlights that button.
 * 3- Clicking a button switches the page.
*/
GtkWidget* navbar(){
    GtkWidget* navbar = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACE);
    gtk_widget_add_css_class(navbar, "navbar");

    GtkWidget* weatherButton = get_nav_button("Weather", "/home/kamran/Projects/GeoGTK/src/assets/placeholder.svg", weather_handler);
    // To make sure intial button is active when app is restarted.
    if(!APP_STATE.prev_focused_button){
        toggle_button_focus(weatherButton);
    }

    // These buttons appear at top of navbar.
    gtk_box_append(GTK_BOX(navbar), weatherButton);
    
    // Adds a space between top and bottom buttons of navbar.
    GtkWidget* spacer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_vexpand(spacer, TRUE);
    gtk_box_append(GTK_BOX(navbar), spacer);
    ////////////////////////////////////////////////////////

    // This button appears at bottom of navbar.
    gtk_box_append(GTK_BOX(navbar), get_nav_button("Settings", "/home/kamran/Projects/GeoGTK/src/assets/settings.svg", settings_handler));

    return navbar;
}