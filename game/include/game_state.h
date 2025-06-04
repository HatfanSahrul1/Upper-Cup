#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "raylib.h"
#include "objects.h"


namespace UpperCup::Game
{
    class IGameState
    {
        public:
            virtual bool Enter() = 0;
            virtual bool MainState() = 0;
            virtual bool Exit() = 0;

            virtual void Render() = 0;
    };

    class HomeScreen : public IGameState
    {
        public:
            bool Enter() override;
            bool MainState() override;
            bool Exit() override;
            void Render() override;
    };

    class Playing : public IGameState
    {
        public:
            bool Enter() override;
            bool MainState() override;
            bool Exit() override;
            void Render() override;

        private:
            float flashTimer_ = 0.1f;
            bool drawFlash_ = false;

             // Efek hancur
            bool isShattered_ = false;
            std::vector<ShatterPiece> pieces_;

            // Fungsi tambahan
            void CreateShatterEffect(Vector2 cupPos);
    };

    class GameOver : public IGameState
    {
        public:
            bool Enter() override;
            bool MainState() override;
            bool Exit() override;
            void Render() override;
    };
}