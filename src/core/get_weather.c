/*
 * The core login for fetching and loading weather data to be
 * displayed is handled here.
*/
#include "../models/weather.h"
#include "../utils/logger.h"
#include "stdlib.h"
#include "../utils/storage.h"
#include "../utils/c_json.h"
#include <string.h>


// Extracts location from weather JSON.
Location get_location_from_json(const cJSON* json){
    cJSON* locationJSON = cJSON_GetObjectItem(json, "location");

    char* name = cJSON_GetObjectItem(locationJSON, "name")->valuestring;
    char* region = cJSON_GetObjectItem(locationJSON, "region")->valuestring;
    char* country = cJSON_GetObjectItem(locationJSON, "country")->valuestring;

    Location location = {};
    strcpy(location.name, name);
    strcpy(location.region, region);
    strcpy(location.country, country);

    return location;
}

// Extracts the current weather data from JSON.
Current get_current_from_json(const cJSON* json){
    cJSON* currentJSON = cJSON_GetObjectItem(json,"current");

    double temperature = cJSON_GetObjectItem(currentJSON, "temp_c")->valuedouble;
    double windSpeed = cJSON_GetObjectItem(currentJSON, "wind_kph")->valuedouble;
    double visibility = cJSON_GetObjectItem(currentJSON, "vis_km")->valuedouble;
    double uvIndex = cJSON_GetObjectItem(currentJSON, "uv")->valuedouble;
    double precipitation = cJSON_GetObjectItem(currentJSON, "precip_mm")->valuedouble;
    int humidity = cJSON_GetObjectItem(currentJSON, "humidity")->valueint;
    int clouds = cJSON_GetObjectItem(currentJSON, "cloud")->valueint;

    Current current = {};
    current.temperature = temperature;
    current.humidity = humidity;
    current.clouds = clouds;
    current.precipitation = precipitation;
    current.visibility = visibility;
    current.uvIndex = uvIndex;
    current.windSpeed = windSpeed;

    return current;
}

/*
 * This function is used to load weather data either from:
 * 1- weather.json file cached from last refresh.
 * 2- fetches data from network API. 
*/
WeatherModel* get_weather_data(){
    log_debug("Getting weather data from core.");
    WeatherModel* model = malloc(sizeof(WeatherModel));

    char* data = get_content("weather.json");

    if(!data){
        log_error("Failed to load weather data.");
        return NULL;
    }

    cJSON* root = cJSON_Parse(data);

    Location location = get_location_from_json(root);

    Current current = get_current_from_json(root);

    model->location = location;
    model->current = current;

    cJSON_Delete(root);

    return model;
}

// Make sure to use this method to clear memory when used get_weather_data()
void clear_weather_model(WeatherModel* model){
    if(model){
        free(model);
        model = NULL;
    }
}