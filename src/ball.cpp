#include <iostream>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Ball.hpp>
#include <tools.hpp>

Ball::Ball(int p_x, int p_y, int p_radius, float p_mass, SDL_Color p_color) : x(p_x), y(p_y), radius(p_radius), mass(p_mass), color(p_color)
{
    drag = pow(mass / (mass + ballConsts::massOfAir), radius);
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

void Ball::updatePosition(float delta_Time, bool shouldGravitize, bool momentumLoss)
{
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
    if (shouldGravitize)
    {
        Vector gravity = Vector(ballConsts::gravity.x, ballConsts::gravity.y * delta_Time);
        Vector v = tools::addALVectors(Vector(angle, speed), gravity);
        angle = v.x;
        speed = v.y;
    }

    if (momentumLoss)
        speed *= drag;
}

SDL_Point Ball::getScreenCoords()
{
    return SDL_Point{.x = (int)x, .y = (int)y};
}
