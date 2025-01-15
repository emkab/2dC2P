#include "scene.hpp"
#include "renderWindow.hpp"

class SceneBasic : public Scene
{
public:
    SceneBasic(RenderWindow window) : Scene(window)
    {
        addBall(260, 260, 100, 10, SDL_Color{.r = 255, .g = 255, .b = 255, .a = 255});
    }

private:
};