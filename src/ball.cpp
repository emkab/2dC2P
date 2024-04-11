#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Ball.hpp>

Ball::Ball(int p_x, int p_y, double p_radius, SDL_Color p_color) : x(p_x), y(p_y), xVelocity(0), yVelocity(0), radius(p_radius), color(p_color)
{
}

std::string Ball::getName()
{
    return name;
}
std::string Ball::setName(std::string p_name)
{
    name = p_name;
    return name;
}

int Ball::getX() { return x; }
int Ball::getY() { return y; }
int Ball::setX(int p_x)
{
    x = p_x;
    return x;
}
int Ball::setY(int p_y)
{
    y = p_y;
    return y;
}
float Ball::getXVelocity() { return xVelocity; }
float Ball::getYVelocity() { return yVelocity; }
float Ball::setXVelocity(float p_xVelocity)
{
    xVelocity = p_xVelocity;
    return xVelocity;
}
float Ball::setYVelocity(float p_yVelocity)
{
    yVelocity = p_yVelocity;
    return yVelocity;
}

double Ball::getRadius()
{
    return radius;
}

double Ball::setRadius(double p_radius)
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

void Ball::updatePosition()
{
    x += xVelocity;
    y += yVelocity;
}
