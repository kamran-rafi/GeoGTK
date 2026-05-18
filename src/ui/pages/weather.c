/*
 * Handle's all the GUI for Showing weather data inside this page.
*/

#include <gtk/gtk.h>
#include "../components/components.h"
#include "../../utils/logger.h"


/*
 * [TODO] This callback function is used to search for weather location.
*/
void search_location(GtkWidget* widget, gpointer input){
    GtkEntryBuffer* buffer = gtk_entry_get_buffer(input);
    const char* text =  gtk_entry_buffer_get_text(buffer);
    log_info("Searching Location: %s", text);
}

/*
 * Todos: 
 * 1- [DONE] Add a Location Search Input.
 * 2- [PENDING] Add Current Weather Temperature and Location Info.
 * 3- [PENDING] Add current Weather Condition Container.
 * 4- [PENDING] Add Hourly Weather Forcast Container. 
 * 5- [PENDING] Add Daily Weather Forcast Container.
*/
GtkWidget* weather_page(){
    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Appended input widget to search for location.
    gtk_box_append(GTK_BOX(root), read_input("Search location...", "Search", search_location));

    return root;
}