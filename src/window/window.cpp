#include "inc/window.hpp"
#include "../util/logger.hpp"

/**
 * Attempt to initialize an SDL window
 * Ctor for window manager class
*/
WindowMgr::WindowMgr(std::string name, const uint16_t w, const uint16_t h) {
    int init_val = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
    if (init_val != 0) {
        Log(ERROR, "SDL failed to initialize! Cause: %s\n", SDL_GetError());
    }
    else {
        // create SDL window
        this->wdw = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
        this->wdw_surface = SDL_GetWindowSurface(this->wdw);
        SDL_UpdateWindowSurface(this->wdw); // display the damn thing
        instance = this;
        // start up event thread stuff
    }
}
WindowMgr::~WindowMgr() {
    checkEventSignal.store(false);
    event_thread.join();
    SDL_DestroyWindow(this->wdw);
    Log(INFO, "Shutting down!\n%s\n\n", SDL_GetError());
}

void WindowMgr::event_handler_init() {
    event_thread = std::thread(_pollEvents);
}

void WindowMgr::_pollEvents() {
    while (instance->checkEventSignal.load()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // handle event
        }
    }
}

