#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include "../models/weather.h"

WeatherModel* get_weather_data();
void clear_weather_model(WeatherModel* model);

#endif