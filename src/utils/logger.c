/*
 * This file's code is responsible for logging different parts of software.
*/

#include <stdio.h>
#include <stdarg.h>

// For general info logging
void log_info(const char* format, ...)
{
    va_list args;

    printf("[INFO] ");

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

// For debugging logging
void log_debug(const char* format, ...)
{
    va_list args;

    printf("[DEBUG] ");

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

// For errors logging
void log_error(const char* format, ...)
{
    va_list args;

    printf("[ERROR] ");

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}