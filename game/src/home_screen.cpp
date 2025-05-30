#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game
{
    bool HomeScreen::Enter() {
        // Inisialisasi jika diperlukan
        return true;
    }

    bool HomeScreen::MainState() {
        // Cek input untuk berpindah ke Playing
        if (IsKeyPressed(KEY_SPACE)) {
            GameManager::GetInstance()->ChangeState(std::make_shared<Playing>());
        }
        return true;
    }

    bool HomeScreen::Exit() {
        return true;
    }

    void HomeScreen::Render() {
        // Gambar judul dan instruksi
        DrawText("UPPERCUP", 200, 200, 60, BLACK);
        DrawText("Press SPACE to Play", 200, 300, 20, DARKGRAY);
    }
}
