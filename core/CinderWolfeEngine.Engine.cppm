module;
#include <GLFW/glfw3.h>
export module CinderWolfeEngine.Engine;
import CinderWolfeEngine.Window;
using namespace CinderWolfeEngine;

namespace CinderWolfeEngine
{
    export class Engine
    {
    public:
        Engine();
        ~Engine();

        bool InitEngine();
        void CoreLoop();

    private:
        void HandleInput();
        void UpdateGame();
        void Render();
        Window mWindow;
    };

    Engine::Engine()
    {
    }

    Engine::~Engine()
    {
    }

    bool Engine::InitEngine()
    {
        if (!mWindow.CreateWindow(1000, 1000, "My Window"))
        {
            return false;
        }
        return true;
    }

    void Engine::CoreLoop()
    {
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(mWindow.GetWindow()))
        {

            HandleInput();
            UpdateGame();
            Render();
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(mWindow.GetWindow());

            /* Poll for and process events */
            glfwPollEvents();
        }
        mWindow.CloseWindow();
    }

    void Engine::HandleInput()
    {
    }

    void Engine::UpdateGame()
    {
    }

    void Engine::Render()
    {
    }
}