/*
 * Widget is used to read input from user.
 * hint: String to show what is purpose of input.
 * label: String to show what happens on clicking.
 * callbackFunc: function to call once the button has been pressed.
*/

#include "gtk/gtk.h"
#include "../ui.h"

GtkWidget* read_input(gchar* hint, gchar* label, void(*callbackFunc)(GtkWidget* widget, gpointer input)){
    GtkWidget* container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, SPACE);

    GtkWidget* input = gtk_entry_new();
    gtk_widget_set_hexpand(input, TRUE);
    gtk_entry_set_placeholder_text(GTK_ENTRY(input), hint);
    gtk_widget_add_css_class(input, "read-input");

    GtkWidget* button = gtk_button_new_with_label(label);
    gtk_widget_add_css_class(button, "read-button");
    gtk_widget_set_cursor_from_name(button, "pointer");
    g_signal_connect(button, "clicked", G_CALLBACK(callbackFunc), input);

    gtk_box_append(GTK_BOX(container), input);
    gtk_box_append(GTK_BOX(container), button);

    return container;
}