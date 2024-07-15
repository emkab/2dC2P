#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"

namespace scenes
{
    class ballSimScene
    {
    public:
        ballSimScene(RenderWindow window);
        void tick(RenderWindow window, float delta_Time);
        void addBall(float x, float y, int radius, SDL_Color color);
        void addBallGrid(float x, float y, int radius, int count, SDL_Color color);
        void mouseEvent(SDL_MouseButtonEvent &e);

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        std::vector<Ball> balls;
        void collideCircle(Ball &ball);
        void collide(Ball &b1, Ball &b2);
        Ball *findBalls(std::vector<Ball> *balls, float x, float y);
        Ball *selectedBall;
        int mouseX, mouseY;
        float delta_Time;
        double dampeningFactor;
        Ball circle;
    };
}