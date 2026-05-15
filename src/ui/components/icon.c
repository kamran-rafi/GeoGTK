/*
 * This file handles creation of icon and returns icon widget.
 * icPath: String containing path of icon.
 * icSize: How large icon should be.
*/

#include <gtk/gtk.h>

GtkWidget* get_icon(char* icPath,const int icSize){
    GdkTexture* tex = gdk_texture_new_from_filename(
        (char*)icPath,
        NULL
    );
    GtkWidget* icon = gtk_image_new_from_paintable(GDK_PAINTABLE(tex));
    gtk_image_set_pixel_size(GTK_IMAGE(icon), icSize);
    g_object_unref(tex);
    return icon;
}