import std;
import CinderWolfeEngine.Engine;
import CinderWolfeEngine.Math;

using namespace CinderWolfeEngine;

int main()
{

    Engine engine;

    const bool engineStarted = engine.InitEngine();

    if (!engineStarted)
    {
        std::println("Could Initialize Engine.");
        return -1;
    }

    engine.CoreLoop();

    return 0;
}