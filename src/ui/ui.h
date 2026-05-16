#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

GtkWidget* navbar();
GtkWidget* render_page();

#define SPACE 8

typedef enum {
    WEATHER_PAGE,
    SETTINGS_PAGE
} Pages;

void set_page(Pages page);

#endif