#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game {

    bool Playing::Enter() {
        frameCount = 0;
        static bool done = false;
        frameCount++;
        
        auto cup = GameManager::GetInstance()->GetCup();
        if (cup->GetPosition().x < 200) {
            cup->MoveAside();
            cup->Floating(false);
            done = false;
        }
        else {
            done  = true;
        }
        
        return done;
    }

    bool Playing::MainState() {
        auto cup = GameManager::GetInstance()->GetCup();
        Camera2D* camera = GameManager::GetInstance()->GetCamera();

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
        GameManager::GetInstance()->SetScore(score);

    return false;
    }

    bool Playing::Exit() {
        return true;
    }

    void Playing::Render() {
        auto cup = GameManager::GetInstance()->GetCup();
        auto camera = GameManager::GetInstance()->GetCamera();

        if (!cup || !camera) return;

        BeginMode2D(*camera);

            cup->Render();
            DrawText("UPPERCUP", 200, 200, 60, BLACK);
            DrawText("Press SPACE to Jump & Play", 200, 300, 20, DARKGRAY);

        EndMode2D();

        DrawText(TextFormat("Score: %.2d", GameManager::GetInstance()->GetScore()), 10, 30, 20, BLACK);
    }

}
