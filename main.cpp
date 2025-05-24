#include "raylib.h"

int main() {
    // Inisialisasi jendela
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Gerak Kotak - WASD");
    SetTargetFPS(60);

    // Posisi awal kotak
    Vector2 position = { screenWidth / 2.0f - 25, screenHeight / 2.0f - 25 };
    const float speed = 5.0f;
    const float boxSize = 50.0f;

    // Game loop utama
    while (!WindowShouldClose()) {
        // Input
        if (IsKeyDown(KEY_W)) position.y -= speed;
        if (IsKeyDown(KEY_S)) position.y += speed;
        if (IsKeyDown(KEY_A)) position.x -= speed;
        if (IsKeyDown(KEY_D)) position.x += speed;

        // Gambar
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Gunakan W A S D untuk gerakkan kotak", 10, 10, 20, DARKGRAY);
        DrawRectangleV(position, {boxSize, boxSize}, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}