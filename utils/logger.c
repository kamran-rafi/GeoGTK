////////////
// LOGGER //
////////////

#include <gtk/gtk.h>

void info(char* msg){
    g_print("[INFO] %s\n", (char*) msg);
}

void error(char* msg){
    g_print("[ERROR] %s\n", (char*) msg);
}
