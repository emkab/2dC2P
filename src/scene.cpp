#include "scene.hpp"
#include "RenderWindow.hpp"

Scene::Scene(RenderWindow window)
{
    SDL_Rect windowSize = window.getWindowSize();

    srand((unsigned)time(NULL));
}

void Scene::tick(RenderWindow window, float delta_Time_In)
{
    delta_Time = delta_Time_In;
    for (Entity &entity : entities)
    {
        window.render(entity);
    }
    int index_x = 0;
    for (Ball &ball : balls)
    {
        int index_y = index_x + 1;
        
        //Insert logic

        window.render(ball, 1);
        index_x++;
    }
}

void Scene::addBall(float x, float y, int radius, float mass, SDL_Color color)
{
    balls.emplace_back(Ball(x, y, radius, mass, color));
    balls.back().speed = 0.01;
    balls.back().angle = M_PI / 2;
}

void Scene::mouseEvent(SDL_MouseButtonEvent &e)
{
    if (e.button == SDL_BUTTON_LEFT)
    {
        switch (e.state)
        {
        case SDL_PRESSED:
        {
            // Insert logic
            break;
        }

        case SDL_RELEASED:
        {
            // Insert logic
            break;
        }
        }
    }
}

    Ball *Scene::findBalls(std::vector<Ball> * balls, float x, float y)
    {
        for (Ball &b : *balls)
        {
            if (hypot(b.x - x, b.y - y) <= b.radius)
            {
                return &b;
            }
        }
        return NULL;
    }