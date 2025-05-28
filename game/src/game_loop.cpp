#include "game_loop.h"

namespace UpperCup::Game
{
    void GameLoop::Run()
    {
        InitWindow(800, 600, "Upper Cup");
        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            Update();
            
            BeginDrawing();
            ClearBackground(RAYWHITE);
            
            Render();
            
            EndDrawing();
        }
        CloseWindow();
    }

    void GameLoop::Update()
    {
        game_manager_->ProccesInput();
    }

    void GameLoop::Render()
    {
        game_manager_->RenderObjects();
    }
}