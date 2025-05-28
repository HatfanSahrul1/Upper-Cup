#pragma once

#include <iostream>
#include <vector>
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

            Objects::Cup cup_;
            Objects::Obstacle obs_;
    };
}