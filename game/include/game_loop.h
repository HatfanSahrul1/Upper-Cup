#pragma once

#include <iostream>


namespace UpperCup::Game
{
    class GameLoop
    {
        public:
            void Run();
            void Update();
            void Render();
            void Stop();

        private:
            bool isRunning;

    };
}