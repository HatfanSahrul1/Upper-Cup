#include "game_state.h"
#include "game_manager.h"
#include "raylib.h"

namespace UpperCup::Game {

    bool Playing::Enter() {
        frameCount = 0;
        return true;
    }

    bool Playing::MainState() {
        frameCount++;
        // Gerakkan cup hingga X = 200
        auto cup = GameManager::GetInstance()->GetCup();
        if (cup->GetPosition().x < 200) {
            Vector2 pos = cup->GetPosition();
            pos.x += 2.0f;
            cup->SetPosition(pos);
        }
        return true;
    }

    bool Playing::Exit() {
        return true;
    }

    void Playing::Render() {
        // Teks "UPPERCUP" tetap muncul tapi bisa digerakkan
        int titleX = 200 - frameCount * 2;
        if (titleX > -400) {
            DrawText("UPPERCUP", titleX, 100, 60, BLACK);
        }

        // Gambar objek dari GameManager (cup, obstacles, dll)
        GameManager::GetInstance()->RenderObjects();
    }

}
