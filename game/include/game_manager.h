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

        private:
            static GameManager* instance;

            GameManager() = default;
    };
}