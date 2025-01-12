#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <vector.hpp>

namespace tools
{
    extern int randomSign();
    extern double normalize(double x);
    extern double getDistance(SDL_Point p1, SDL_Point p2);
    extern double getDistance(int p1, int p2);
    extern SDL_Point get_Size(SDL_Texture *texture);
    extern SDL_Color newColor(Uint8 p_r, Uint8 p_g, Uint8 p_b, Uint8 p_a);
    extern void DrawCircle(SDL_Renderer *renderer, SDL_Point center, int radius, SDL_Color color);
    extern void DrawFullCircle(SDL_Renderer *renderer, SDL_Point center, int radius, SDL_Color color);
    extern Vector addALVectors(Vector v1, Vector v2);
    extern void write(std::string text, int x, int y, SDL_Color color, TTF_Font *font);
}