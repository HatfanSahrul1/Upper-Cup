#pragma once

#include <iostream>
#include <vector>
#include "objects.h"


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

            UpperCup::Objects::Cup cup_;
    };
}