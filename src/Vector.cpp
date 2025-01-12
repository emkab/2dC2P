#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>

#include <Vector.hpp>

Vector::Vector() : x(0), y(0)
{
}

Vector::Vector(float p_x, float p_y) : x(p_x), y(p_y)
{
}

Vector Vector::multiply(float f)
{
    return Vector(x * f, y * f);
}

Vector Vector::normal()
{
    return Vector(x != 0 ? x / abs(x) : 0, y != 0 ? y / abs(y) : 0);
}

void Vector::normalize()
{
    (x, y) = (normal().x, normal().y);
}

SDL_Point Vector::toPoint()
{
    return SDL_Point{.x = (int)x, .y = (int)y};
}