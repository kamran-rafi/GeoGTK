/*
 * The core login for fetching and loading weather data to be
 * displayed is handled here.
*/
#include "../models/weather.h"
#include "../utils/logger.h"
#include "stdlib.h"

/*
 * This function is used to load weather data either from:
 * 1- weather.json file cached from last refresh.
 * 2- fetches data from network API. 
*/
WeatherModel* get_weather_data(){
    log_debug("Getting weather data from core.");
    WeatherModel *model = (WeatherModel*) malloc(sizeof(WeatherModel));

    Location location = {
        "Lahore",
        "Punjab",
        "Pakistan"
    };

    Current current = {
        36.1,
        7.6,
        9.6,
        5.6,
        6.9,
        2,
        69
    };

    model->location = location;
    model->current = current;

    return model;
}

// Make sure to use this method to clear memory when used get_weather_data()
void clear_weather_model(WeatherModel* model){
    if(model){
        free(model);
        model = NULL;
    }
}