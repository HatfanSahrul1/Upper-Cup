#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game 
{
    bool Playing::Enter() {
        auto game = GameManager::GetInstance();
        bool done = false;
        auto cup = game->GetCup();

        if (cup->GetPosition().x < 200) {
            game->ResetCamera();

            cup->MoveAside();
            cup->Floating(false);
        }
        else
        {
            game->GetObstacleManager()->CreateObstacle();
            done = true;
        }
        
        return done;
    }

    bool Playing::MainState() {
        auto game = GameManager::GetInstance();
        auto cup = game->GetCup();
        Camera2D* camera = game->GetCamera();

        if (camera == nullptr || cup == nullptr) {
            TraceLog(LOG_ERROR, "Camera or Cup is null!");
            return false;
        }

        int screenHeight = GetScreenHeight();
        camera->target.x = cup->GetPosition().x + 200;
        camera->target.y = screenHeight / 2.0f;

        // Update cup
        bool isJumping = IsKeyDown(KEY_SPACE);
        cup->MoveAside();
        cup->Floating(isJumping);

        int score = cup->GetPosition().x * 0.1;
        game->SetScore(score);

        if(game->GetObstacleManager()->IsCollide(*cup->GetCollider())) return true;

        return false;
    }

    bool Playing::Exit() {
        flashTimer_ -= GetFrameTime();
        if (flashTimer_ > 0.0f) {
            drawFlash_ = true;
        } else {
            flashTimer_ = 0.1f;
            GameManager::GetInstance()->ChangeState(std::make_shared<GameOver>());
            return true;
        }
        return false;
    }

    void Playing::Render() {
        auto game = GameManager::GetInstance();
        auto cup = game->GetCup();
        auto camera = game->GetCamera();

        if (!cup || !camera) return;

        BeginMode2D(*camera);
            DrawText("UPPERCUP", 200, 200, 60, BLACK);
            DrawText("Press [SPACE] to Jump & Play", 200, 300, 20, DARKGRAY);

            cup->Render();
            
            game->GetObstacleManager()->RenderObstacles();
        EndMode2D();

        DrawText(TextFormat("Score: %.2d", game->GetScore()), 10, 30, 20, BLACK);

        if(drawFlash_) DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(WHITE, 0.8f));
    }

}
