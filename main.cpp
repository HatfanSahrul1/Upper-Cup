#include "raylib.h"
#include "game_loop.h"
#include "game_manager.h"

int main() {
    UpperCup::Game::GameLoop UpperCup;
    
    UpperCup.Run();
    
    return 0;
}