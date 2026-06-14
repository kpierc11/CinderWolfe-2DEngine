export module CinderWolfeEngine.Engine;
import CinderWolfeEngine.Window;

namespace CinderWolfeEngine::Engine
{
    export class Engine
    {
    public:
        Engine();
        ~Engine();

        void InitEngine();
    };

    Engine::Engine()
    {
    }

    Engine::~Engine()
    {
    }

    void Engine::InitEngine()
    {
        InitWindow();
    }
}