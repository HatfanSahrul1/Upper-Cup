#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game
{
    bool HomeScreen::Enter() {
        return true;
    }

    bool HomeScreen::MainState() {
        if (IsKeyPressed(KEY_SPACE)) {
            GameManager::GetInstance()->ChangeState(std::make_shared<Playing>());
        }
        return false;
    }

    bool HomeScreen::Exit() {
        return true;
    }

    void HomeScreen::Render() {
        DrawText("UPPERCUP", 200, 200, 60, BLACK);
        DrawText("Press SPACE to Jump & Play", 200, 300, 20, DARKGRAY);
    }
}
