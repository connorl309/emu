#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include "../../util/common.hpp"
#include <atomic>

class WindowMgr
{

private:
    SDL_Window* wdw;
    SDL_Surface* wdw_surface;
    std::thread event_thread;
    std::atomic<bool> checkEventSignal;
    std::chrono::high_resolution_clock fastclk;
    WindowMgr* instance;

    void _pollEvents();

public:
    WindowMgr(std::string name, const uint16_t w, const uint16_t h);
    ~WindowMgr();
    void event_handler_init();
};

#endif