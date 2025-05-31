#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game
{
    bool GameOver::Enter()
    {

        return true;
    }

    bool GameOver::MainState()
    {
        auto game = GameManager::GetInstance();
        if(IsKeyPressed(KEY_R)){
            game->ResetCup();
            game->ChangeState(std::make_shared<Playing>());
        }
        return false;
    }

    bool GameOver::Exit()
    {

        return false;
    }

    void GameOver::Render(){
        auto game = GameManager::GetInstance();
        auto cup = game->GetCup();
        auto camera = game->GetCamera();

        if (!cup || !camera) return;

        BeginMode2D(*camera);

            cup->Render();
            
            game->GetObstacleManager()->RenderObstacles(); 
        EndMode2D();
    }
}