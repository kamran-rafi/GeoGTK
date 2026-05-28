#ifndef FORMATTER_H
#define FORMATTER_H

#include "../models/weather.h"

char* get_formatted_location(Location location);
char* get_formatted_temperature(double temperature);

#endif