#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Vector
{
public:
    Vector();
    Vector(float p_x, float p_y);
    float x, y;
    Vector multiply(float f);
    Vector normal();
    void normalize();
    SDL_Point toPoint();
};