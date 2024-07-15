#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#include <Ball.hpp>
#include <tools.hpp>

Ball::Ball(int p_x, int p_y, int p_radius, SDL_Color p_color) : x(p_x), y(p_y), radius(p_radius), color(p_color)
{
}

int Ball::getRadius()
{
    return radius;
}

int Ball::setRadius(int p_radius)
{
    radius = p_radius;
    return radius;
}

SDL_Color Ball::getColor()
{
    return color;
}
SDL_Color Ball::setColor(SDL_Color p_color)
{
    color = p_color;
    return color;
}

void Ball::updatePosition(float delta_Time)
{
    Vector gravity = Vector(ballConsts::gravity.x, ballConsts::gravity.y * delta_Time);
    std::cout << angle << ", " << speed << ", " << delta_Time << std::endl;
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
    Vector v = tools::addALVectors(Vector(angle, speed), gravity);
    angle = v.x;
    speed = v.y;
    speed *= ballConsts::drag;

    // std::cout << angle << ", " << speed << std::endl;
}

SDL_Point Ball::getScreenCoords()
{
    return SDL_Point{.x = (int)x, .y = (int)y};
}
