module;
#include <GLFW/glfw3.h>
export module CinderWolfeEngine.Window;
import std;

namespace CinderWolfeEngine
{

    export class Window
    {
    public:
        Window();
        ~Window();
        bool CreateWindow(int width, int height, const char *name);
        GLFWwindow *GetWindow() const { return window; };
        void CloseWindow();

    private:
        GLFWwindow *window;
    };

    Window::Window() : window(nullptr)
    {
    }

    Window::~Window()
    {
    }

    bool Window::CreateWindow(int width, int height, const char *name)
    {
        /* Initialize the library */
        if (!glfwInit())
            return false;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(width, height, name, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return false;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        return true;
    }
    void Window::CloseWindow()
    {
        glfwTerminate();
    }
}