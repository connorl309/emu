#include "inc/window.hpp"
#include "../util/logger.hpp"

/**
 * Attempt to initialize an SDL window
 * Ctor for window manager class
*/
WindowMgr::WindowMgr(std::string name, const uint16_t w, const uint16_t h) {
    int init_val = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
    if (init_val != 0) {
        LOG(ERROR, "SDL failed to initialize! Cause: %s\n", SDL_GetError());
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
    LOG(INFO, "Shutting down!\n%s\n", SDL_GetError());
}

void WindowMgr::event_handler_init() {
    event_thread = std::thread(_pollEvents, this);
}

/**
 * Poll events happening in the window
 * 
 * this runs on a separate thread, which is killed upon exit of the 
 * program.
*/
void WindowMgr::_pollEvents(WindowMgr* instance) {
    while (instance->checkEventSignal.load()) {
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            bool needRedraw = false;

            // handle event
            switch (e.type) {
                // keypress
                case SDL_KEYDOWN: {
                    int32_t key = e.key.keysym.sym;
                    if (key == SDLK_ESCAPE)
                        instance->isRunning.store(false);
                    LOG(INFO, "Event - Keypress: %d\n", key);
                    break;
                }
                case SDL_WINDOWEVENT: {
                    if (e.window.event == SDL_WINDOWEVENT_CLOSE)
                        instance->isRunning.store(false);
                    break;
                }

                default: 
                    break;
            }
        }
    }
}

