#pragma once

#include <iostream>


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