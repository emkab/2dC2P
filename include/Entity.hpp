#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture *p_tex);
    float getX();
    float getY();
    float setX(float p_x);
    float setY(float p_y);
    float getXVelocity();
    float getYVelocity();
    float setXVelocity(float p_xVelocity);
    float setYVelocity(float p_yVelocity);
    SDL_Texture *getTex();
    SDL_Rect getCurrentFrame();
    void updatePosition();

private:
    float x, y;
    float xVelocity, yVelocity;
    SDL_Rect currentFrame;
    SDL_Texture *tex;
};