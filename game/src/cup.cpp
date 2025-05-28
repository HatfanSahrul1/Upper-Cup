#include "objects.h"

namespace UpperCup::Objects
{
    Cup::Cup(Vector2 startPos) : position(startPos) {}

    void Cup::Render()
    {
        Rectangle cupBody = {
            position.x - width/2, 
            position.y - height/2, 
            width, 
            height
        };
        DrawRectangle(cupBody.x, cupBody.y, cupBody.width, cupBody.height, GRAY);
        DrawRectangleLines(cupBody.x, cupBody.y, cupBody.width, cupBody.height, BLACK);
        
        Rectangle handle = {
            position.x + width/2, 
            position.y - 10, 
            8, 
            20
        };
        DrawRectangleLines(handle.x, handle.y, handle.width, handle.height, BLACK);
    }

    void Cup::Floating(bool isJetpackActive)
    {
        float dt = GetFrameTime();

        if (isJetpackActive) {
            velocityY += lift * dt;
        } else {
            velocityY += gravity * dt;
        }

        position.y += velocityY * dt;

        // Batas atas & bawah
        if (position.y < maxHeight) {
            position.y = maxHeight;
            velocityY = 0;
        } else if (position.y > groundY) {
            position.y = groundY;
            velocityY = 0;
        }
    }

    
    Vector2 Cup::GetPosition() const {
        return position;
    }
}