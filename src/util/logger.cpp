#include "logger.hpp"

void __Log(LOG_LEVEL level, std::string msg, ...) {
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