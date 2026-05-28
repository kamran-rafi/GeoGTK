/*
 * This file contains functions for formatting data to be used with GTK widgets.
 * Don't forget to clear out heap memory after using any function from here.
*/

#include "logger.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/weather.h"

// This function concatinates two strings together. And returns a new string.
char* concat_strings(const char* str1, const char* str2){

    // A null pointer check.
    if(!str1 || !str2){
        log_error("Not valid param for concatinating strings.");
        return NULL;
    }

    // Add the length of both strings plus 1 (for null termination).
    size_t newStrLength = strlen(str1) + strlen(str2) + 1;

    // Assign Memory from Heap.
    char* newStr = malloc(newStrLength);

    // Concatinate both strings.
    snprintf(newStr, newStrLength, "%s%s", str1, str2);
    
    return newStr;
}

// Uses Location data to return a formmatted String to GUI.
char* get_formatted_location(Location location){

    char* formattedLocation = NULL;

    // Appends the comma separator to city.
    char* formattedCity = concat_strings(location.name, ", ");

    // Appends the country to formatted city.
    char* concatCountry = concat_strings(formattedCity, location.country);

    free(formattedCity); // Clean up formatted city here and 

    // Don't forget to Clean the memory inside the function caller.
    formattedLocation = concatCountry;

    return formattedLocation;
}

char* get_formatted_temperature(double temperature){
    char* formattedTemperature = NULL;

    // Convert the temperature double value to char string.
    char temperatureStr[6];
    snprintf(temperatureStr, sizeof(temperatureStr), "%.1f", temperature);

    // Appends the unit to temperature string.
    char* concatUnit = concat_strings(temperatureStr, "°C");

    // Don't forget to Clean the memory inside the function caller.
    formattedTemperature = concatUnit;

    return formattedTemperature;
}