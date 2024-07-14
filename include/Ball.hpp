#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Vector.hpp>

class Ball
{
public:
    Ball(int p_x, int p_y, int p_radius, SDL_Color p_color);
    float x, y, speed, angle;
    SDL_Point getScreenCoords();
    int radius;
    int getRadius();
    int setRadius(int p_radius);
    SDL_Color getColor();
    SDL_Color setColor(SDL_Color p_color);
    void updatePosition(float delta_Time);

private:
    std::string name;
    SDL_Color color;
};

namespace ballConsts
{
    const float elasticity = 0.75;
    const float drag = 0.999;
    const Vector gravity(M_PI, 9.81);
};