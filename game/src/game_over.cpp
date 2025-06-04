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

            game->GetObstacleManager()->RenderObstacles(); 
        EndMode2D();

        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.7f));

        const char* gameOverText = "GAME OVER";
        int fontSize = 60;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), gameOverText, fontSize, 2);
        DrawText(gameOverText, 
                (GetScreenWidth() - textSize.x) / 2, 
                (GetScreenHeight() - textSize.y) / 2 - 50, 
                fontSize, RED);

        int score = game->GetScore();
        const char* scoreText = TextFormat("Score: %i", score);
        Vector2 scoreSize = MeasureTextEx(GetFontDefault(), scoreText, 30, 2);
        DrawText(scoreText,
                (GetScreenWidth() - scoreSize.x) / 2,
                (GetScreenHeight() - scoreSize.y) / 2 + 40,
                30, WHITE);

        const char* restartText = "Press [R] to Restart";
        Vector2 restartSize = MeasureTextEx(GetFontDefault(), restartText, 20, 2);
        DrawText(restartText,
                (GetScreenWidth() - restartSize.x) / 2,
                (GetScreenHeight() - restartSize.y) / 2 + 100,
                20, LIGHTGRAY);
    }
}