#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Ball.hpp"

namespace scenes
{
    class ballSimScene
    {
    public:
        ballSimScene(RenderWindow window, int ballCount, bool p_gravityToggle, bool randDensity, int randSpeed, bool p_momentumLoss);
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
        Ball *selectedBall, *debugBall;
        SDL_Color selectedBallOriginalColor, debugBallOriginalColor;
        int mouseX, mouseY;
        float delta_Time;
        double dampeningFactor;
        Ball circle;
        bool momentumLoss, gravityToggle;
        TTF_Font *font;
    };
}