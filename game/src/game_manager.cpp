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
        // if (currentState_) {
        //     currentState_->MainState();
        // }
        bool isJumping = IsKeyDown(KEY_SPACE);
        cup_->Floating(isJumping);

        if(IsKeyDown(KEY_V)){
            float deltaT = GetFrameTime();
            obs_->Move(deltaT);
        }
    }

    void GameManager::RenderObjects()
    {
        for(auto* obj : Objects::RenderableObjects)
        {
            obj->Render();
        }
    //    if (currentState_) {
    //         currentState_->Render(); // Panggil render per state
    //     }
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