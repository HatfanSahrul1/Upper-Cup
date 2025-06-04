#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game 
{
    bool Playing::Enter() {
        auto game = GameManager::GetInstance();
        bool done = false;
        auto cup = game->GetCup();
        int init_score = 0;

        if (cup->GetPosition().x < 200) {
            game->ResetCamera();

            cup->MoveAside();
            cup->Floating(false);
            game->SetScore(init_score);
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

        float cameraX = camera->target.x - 400;
        game->GetObstacleManager()->CycleObstalce(cameraX);

        int score = cup->GetPosition().x * 0.1;
        game->SetScore(score);

        if(game->GetObstacleManager()->IsCollide(*cup->GetCollider())) return true;

        return false;
    }

    bool Playing::Exit() {
    auto game = GameManager::GetInstance();
    auto cup = game->GetCup();

    if (!isShattered_) {
        CreateShatterEffect(cup->GetPosition());
        isShattered_ = true;
    }

    flashTimer_ -= GetFrameTime();
    drawFlash_ = (flashTimer_ > 0.0f);

    Camera2D* camera = game->GetCamera();
    if (camera) {
        camera->target.x += GetRandomValue(-5, 5);
        camera->target.y += GetRandomValue(-5, 5);
    }

    float deltaTime = GetFrameTime();
    for (auto& piece : pieces_) {
        piece.position.x += piece.velocity.x * deltaTime;
        piece.position.y += piece.velocity.y * deltaTime;
        piece.velocity.y += 500.0f * deltaTime;
    }

    static float exitTimer = 0.5f;
    exitTimer -= deltaTime;

    if (exitTimer <= 0.0f) {
        exitTimer = 0.5f;
        game->ChangeState(std::make_shared<GameOver>());
        return true;
    }

    return false;
    }

    void Playing::Render() {
        auto game = GameManager::GetInstance();
        auto cup = game->GetCup();
        auto camera = game->GetCamera();

        BeginMode2D(*camera);

            DrawText("UPPERCUP", 200, 200, 60, BLACK);
            DrawText("Press [SPACE] to Jump & Play", 200, 300, 20, DARKGRAY);

            if (!isShattered_) {
                cup->Render();
            }

            game->GetObstacleManager()->RenderObstacles();

            for (const auto& piece : pieces_) {
                DrawRectangle(
                    piece.position.x,
                    piece.position.y,
                    piece.size,
                    piece.size,
                    DARKGRAY
                );
            }

        EndMode2D();

        DrawText(TextFormat("Score: %.2d", game->GetScore()), 10, 30, 20, BLACK);

        if (drawFlash_) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(RED, 0.3f));
        }
    }


    void Playing::CreateShatterEffect(Vector2 cupPos)
    {
        const int pieceCount = 8; 
        const float baseSize = 10.0f;

        for (int i = 0; i < pieceCount; ++i) {
            float angle = GetRandomValue(0, 360) * DEG2RAD;
            float speed = GetRandomValue(200, 500);

            Vector2 velocity = {
                cosf(angle) * speed,
                sinf(angle) * speed
            };

            pieces_.push_back({
                {cupPos.x, cupPos.y},
                velocity,
                baseSize
            });
        }
    }
}
