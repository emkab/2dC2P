#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector.hpp>

class Ball
{
public:
    Ball(int p_x, int p_y, int p_radius, float p_mass, SDL_Color p_color);
    float x, y, speed, angle, mass, drag;
    SDL_Point getScreenCoords();
    int radius;
    int getRadius();
    int setRadius(int p_radius);
    SDL_Color getColor();
    SDL_Color setColor(SDL_Color p_color);
    void updatePosition(float delta_Time, bool shouldGravitize, bool momentumLoss);

private:
    std::string name;
    SDL_Color color;
};

namespace ballConsts
{
    const float elasticity = 0.75;
    const float globalDrag = 0.999;
    const float massOfAir = 0.2;
    const Vector gravity(M_PI, 9.81);
};