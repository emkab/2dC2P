#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "tools.hpp"

namespace tools
{
    SDL_Point get_Size(SDL_Texture *texture)
    {
        SDL_Point size;
        SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
        return size;
    }

    SDL_Color new_Color(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a)
    {
        return SDL_Color{.r = p_r, .g = p_g, .b = p_b, .a = p_a};
    }
}