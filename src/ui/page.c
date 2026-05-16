/*
 * Code on this page is responsible for rendering current selected page.
*/

#include <gtk/gtk.h>
#include "glib.h"
#include "ui.h"
#include "pages/pages.h"
#include "../utils/logger.h"
#include "../app.h"

// This function is called by the navbar buttons inside navbar.c file.
void set_page(Pages page){

    // Make sure the page_container box and its child exists to clear before rendering new page.
    if(APP_STATE.page_container && APP_STATE.current_page){
        gtk_box_remove(GTK_BOX(APP_STATE.page_container), APP_STATE.current_page);
    }

    switch (page) {
        case WEATHER_PAGE: 
            gtk_box_append(GTK_BOX(APP_STATE.page_container), weather_page());
            break;
        case EARTHQUAKE_PAGE:
            gtk_box_append(GTK_BOX(APP_STATE.page_container), earthquake_page());
            break;
        case SETTINGS_PAGE: 
            gtk_box_append(GTK_BOX(APP_STATE.page_container), settings_page());
            break;
        default: log_error("Invalid page selection. Check your Pages enum!"); break;
    }
}

// Render Page container and inside this container render required page.
GtkWidget* render_page(){
    APP_STATE.page_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, SPACE);
    gtk_widget_set_hexpand(APP_STATE.page_container, TRUE);
    gtk_widget_set_vexpand(APP_STATE.page_container, TRUE);

    // Showing our default page on launch.
    APP_STATE.current_page = weather_page();
    gtk_box_append(GTK_BOX(APP_STATE.page_container), APP_STATE.current_page);

    return APP_STATE.page_container;
}