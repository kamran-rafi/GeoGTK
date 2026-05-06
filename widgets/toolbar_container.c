/*
 * Toolbar container which is shown on left side of window.
 * It will contain options like settings and theme switch etc.
*/
#include <gtk/gtk.h>
#include "../utils/constants.h"


GtkWidget* toolbar_container(){
    GtkWidget* toolbar = gtk_box_new(GTK_ORIENTATION_VERTICAL, PADDING);
    // Style is applied through GTK CSS so passed a classname to refer inside CSS.
    gtk_widget_add_css_class(toolbar, "toolbar-container");
    return toolbar;
}
