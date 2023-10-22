#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include "../util/common.hpp"

class WindowMgr
{

private:
    SDL_Window* wdw;
    SDL_Surface* wdw_surface;

public:
    WindowMgr(std::string name, const uint16_t w, const uint16_t h);
    ~WindowMgr();
};

#endif