#pragma once

#include <iostream>
#include <vector>
#include "game_state.h"
#include "objects.h"
#include "factories.h"
#include "obstacle_manager.h"

using namespace UpperCup;

namespace UpperCup::Game
{
    class GameManager
    {
        public:
            static GameManager* GetInstance();

            void ProccesInput();
            void RenderObjects();

            void ChangeState(std::shared_ptr<IGameState> newState);

            std::shared_ptr<Objects::Cup> GetCup();
            Camera2D* GetCamera();
            void ResetCup();
            void ResetCamera();

            void SetScore(int& i);
            int GetScore();
            
            ObstacleManager* GetObstacleManager();
        private:
            static GameManager* instance;
            GameManager();
            int local_state_ = 0;
            int score_ = 0;

            Camera2D camera_ = {0};

            ObstacleManager obs_manager_;

            std::shared_ptr<IGameState> currentState_ = nullptr;
            std::shared_ptr<Objects::Cup> cup_;
            std::shared_ptr<Objects::Wall> top_, bottom_;
    };
}