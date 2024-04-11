#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Ball
{
public:
    Ball(int p_x, int p_y, double p_radius, SDL_Color p_color);
    std::string getName();
    std::string setName(std::string p_name);
    int getX();
    int getY();
    int setX(int p_x);
    int setY(int p_y);
    float getXVelocity();
    float getYVelocity();
    float setXVelocity(float p_xVelocity);
    float setYVelocity(float p_yVelocity);
    double getRadius();
    double setRadius(double p_radius);
    SDL_Color getColor();
    SDL_Color setColor(SDL_Color p_color);
    void updatePosition();

private:
    std::string name;
    int x, y;
    float xVelocity, yVelocity;
    double radius;
    SDL_Color color;
};