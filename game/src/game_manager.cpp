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
    : cup_({100, 300}), obs_({400, 100}, 300, 190)
    {}

    void GameManager::ProccesInput()
    {
        bool isJumping = IsKeyDown(KEY_SPACE);
        cup_.Floating(isJumping);
    }

    void GameManager::RenderObjects()
    {
        cup_.Render();
    }
}