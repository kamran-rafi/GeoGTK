#ifndef COMPONENTS_H_INCLUDED
#define COMPONENTS_H_INCLUDED

#include <gtk/gtk.h>

GtkWidget* get_icon(char* icPath, int icSize);
GtkWidget* read_input(gchar* hint, gchar* label, void(*callbackFunc)(GtkWidget* widget, gpointer input));

#endif