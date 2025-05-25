#include "game_manager.h"

namespace UpperCup::Game
{
    GameManager* GameManager::instance = nullptr;
    GameManager::GameManager* GetInstance()
    {
        if(!instance){
            instance = new GameManager();
        }
        return instance;
    }
}