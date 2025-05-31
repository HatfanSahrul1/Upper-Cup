#include "game_manager.h"

namespace UpperCup::Game
{
    GameManager* GameManager::instance = nullptr;

    GameManager* GameManager::GetInstance()
    {
        if(!instance){
            instance = new GameManager();
        }
        return instance;
    }

    GameManager::GameManager()
    {
        cup_ = Factories::CupFactory::CreateCup({100, 300});
        obs_ = Factories::ObstacleFactory::CreateObstacle({400, 100}, 400, 800);
        top_ = Factories::WallFactory::CreateWall("top", 600);
        bottom_ = Factories::WallFactory::CreateWall("bottom", 600);

        currentState_ = std::make_shared<HomeScreen>();
        currentState_->Enter();
    }

    void GameManager::ProccesInput()
    {
        switch (local_state_)
        {
        case 0:
            if (currentState_->Enter()){
                local_state_++;
            }
            break;

        case 1:
            if (currentState_->MainState()){
                local_state_++;
            }
            break;
        
        case 2:
            if (currentState_->Exit()){
                local_state_ = 0;
            }
            break;
        }
    }

    void GameManager::RenderObjects()
    {
        
        if (currentState_) {
            currentState_->Render();
        }

        top_->Render();
        bottom_->Render();
    }

    void GameManager::ChangeState(std::shared_ptr<IGameState> newState)
    {
        if (currentState_)
            currentState_->Exit();

        currentState_ = newState;
        currentState_->Enter();
    }

    std::shared_ptr<Objects::Cup> GameManager::GetCup()
    {
        return cup_;
    }
}