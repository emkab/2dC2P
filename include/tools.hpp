#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Vector.hpp>

namespace tools
{
    extern int randomSign();
    extern double normalize(double x);
    extern double getDistance(SDL_Point p1, SDL_Point p2);
    extern double getDistance(int p1, int p2);
    extern SDL_Point get_Size(SDL_Texture *texture);
    extern SDL_Color new_Color(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a);
    extern void DrawCircle(SDL_Renderer *renderer, SDL_Point center, int radius, SDL_Color color);
    extern void DrawFullCircle(SDL_Renderer *renderer, SDL_Point center, int radius, SDL_Color color);
    extern Vector addALVectors(Vector v1, Vector v2);
}