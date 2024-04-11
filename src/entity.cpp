#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Entity.hpp>

Entity::Entity(float p_x, float p_y, SDL_Texture *p_tex) : x(p_x), y(p_y), xVelocity(0), yVelocity(0), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

float Entity::getX() { return x; }
float Entity::getY() { return y; }
float Entity::setX(float p_x)
{
    x = p_x;
    return x;
}
float Entity::setY(float p_y)
{
    y = p_y;
    return y;
}
float Entity::getXVelocity() { return xVelocity; }
float Entity::getYVelocity() { return yVelocity; }
float Entity::setXVelocity(float p_xVelocity)
{
    xVelocity = p_xVelocity;
    return xVelocity;
}
float Entity::setYVelocity(float p_yVelocity)
{
    yVelocity = p_yVelocity;
    return yVelocity;
}
SDL_Texture *Entity::getTex() { return tex; }
SDL_Rect Entity::getCurrentFrame() { return currentFrame; }

void Entity::updatePosition()
{
    x += xVelocity;
    y += yVelocity;
}
