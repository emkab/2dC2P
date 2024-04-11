#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "tools.hpp"

namespace tools
{
    SDL_Point getsize(SDL_Texture *texture)
    {
        SDL_Point size;
        SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
        return size;
    }
}