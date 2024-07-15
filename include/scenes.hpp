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
        ballSimScene(RenderWindow window, bool gravity);
        void tick(RenderWindow window, float delta_Time);
        void addBall(float x, float y, int radius, float mass, SDL_Color color);
        void addBallGrid(float x, float y, int radius, float mass, int count, bool randDensity, SDL_Color color);
        void mouseEvent(SDL_MouseButtonEvent &e);

    private:
        SDL_Rect windowSize;
        std::vector<Entity> entities;
        std::vector<Ball> balls;
        void collideCircle(Ball &ball);
        void collide(Ball &b1, Ball &b2);
        Ball *findBalls(std::vector<Ball> *balls, float x, float y);
        Ball *selectedBall;
        SDL_Color selectedBallOriginalColor;
        int mouseX, mouseY;
        float delta_Time;
        double dampeningFactor;
        Ball circle;
    };
}