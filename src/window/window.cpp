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
        isRunning.store(true);
        checkEventSignal.store(true);
        // start up event thread stuff
        event_handler_init();
    }
}
WindowMgr::~WindowMgr() {
    checkEventSignal.store(false); // terminate event thread
    event_thread.join();
    SDL_DestroyWindow(this->wdw);
    Log(INFO, "Shutting down!\n%s\n\n", SDL_GetError());
}

void WindowMgr::event_handler_init() {
    event_thread = std::thread(_pollEvents, this);
}

void WindowMgr::_pollEvents(WindowMgr* instance) {
    while (instance->checkEventSignal.load()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // handle event
            switch (e.type) {

                case SDL_KEYDOWN: {
                    Log(INFO, "Handling event - Keypress\n");
                    int32_t key = e.key.keysym.sym;
                    if (key == SDLK_ESCAPE)
                        instance->isRunning.store(false);
                    break;
                }

                default: 
                    break;
            }
        }
    }
}

