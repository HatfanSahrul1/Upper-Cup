#pragma once

#include <iostream>
#include <vector>
#include "game_state.h"
#include "objects.h"
#include "factories.h"

using namespace UpperCup;

namespace UpperCup::Game
{
    class GameManager
    {
        public:
            static GameManager* GetInstance();

            void ProccesInput();
            void RenderObjects();
        private:
            static GameManager* instance;
            GameManager();

            std::shared_ptr<Objects::Cup> cup_;
            std::shared_ptr<Objects::Obstacle> obs_;
            std::shared_ptr<Objects::Wall> top_, bottom_;
    };
}