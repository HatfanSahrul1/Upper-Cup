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
    }

    void GameManager::ProccesInput()
    {
        bool isJumping = IsKeyDown(KEY_SPACE);
        cup_.Floating(isJumping);
    }

    void GameManager::RenderObjects()
    {
        for(auto* obj : Objects::RenderableObjects)
        {
            obj->Render();
        }
    }
}