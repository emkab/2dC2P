#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace tools
{
    extern SDL_Point get_Size(SDL_Texture *texture);
    extern SDL_Color new_Color(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a);
}