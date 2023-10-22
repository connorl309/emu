#ifndef LOGGER_HPP
#define LOGGER_HPP

/**
 * A small logger file
*/

#include <string>
#include <stdarg.h>

typedef enum {
    INFO,
    WARNING,
    ERROR
} LOG_LEVEL;

void Log(LOG_LEVEL level, std::string msg, ...) {
    va_list arguments;
    va_start(arguments, msg);
    switch (level) {
        case LOG_LEVEL::INFO:
            printf("[ INFO ] ");
            break;
        case LOG_LEVEL::WARNING:
            printf("[ WARNING ] ");
            break;
        case LOG_LEVEL::ERROR:
            printf("[ !ERROR! ] ");
            break;
    }
    vprintf(msg.c_str(), arguments);
}

#endif