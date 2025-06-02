#pragma once

#include <iostream>
#include "game_manager.h"

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
            GameManager* game_manager_ = nullptr;

    };
}