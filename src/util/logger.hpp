#ifndef LOGGER_HPP
#define LOGGER_HPP

/**
 * A small logger file
*/

#include <string>
#include <stdarg.h>
#include <mutex>

typedef enum {
    INFO,
    WARNING,
    ERROR
} LOG_LEVEL;

static std::mutex log_lock;

// Funky log macro that does some mutex stuff around the log call itself
// maybe not needed, I have no clue.
#define LOG(level, msg, ...) \
    {   \
    std::unique_lock<std::mutex> loglock(log_lock, std::defer_lock);    \
    if (loglock.try_lock()) { \
        __Log((level), msg, __VA_ARGS__); \
        loglock.unlock();   \
    }   \
    }   \

void __Log(LOG_LEVEL level, std::string msg, ...);

#endif