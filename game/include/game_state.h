#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"


namespace UpperCup::Game
{
    class IGameState
    {
        public:
            virtual bool Enter() = 0;
            virtual bool MainState() = 0;
            virtual bool Exit() = 0;
    };

    class HomeScreen : public IGameState
    {
        public:
            bool Enter() override;
            bool MainState() override;
            bool Exit() override;
    };

    class Playing : public IGameState
    {
        public:
            bool Enter() override;
            bool MainState() override;
            bool Exit() override;
    };

    class GameOver : public IGameState
    {
        public:
            bool Enter() override;
            bool MainState() override;
            bool Exit() override;
    };
}