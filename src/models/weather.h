/* 
 * This file contains structs for containing data related to weather.
*/

#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

// For containing location info of weather.
typedef struct {
    char name[128];
    char region[128];
    char country[128];
} Location;

// For containing current data of weather.
typedef struct {
    float temperature;
    float windSpeed;
    float visibility;
    float precipitation;
    float uvIndex;
    int clouds;
    int humidity;
} Current;

typedef struct {
    Location location;
    Current current;
} WeatherModel;

#endif