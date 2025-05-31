#include "objects.h"

namespace UpperCup::Objects
{
    Cup::Cup(Vector2 startPos) 
    : position_(startPos) 
    {}

    void Cup::Render()
    {
        collider_ = {
            position_.x - WIDTH/2, 
            position_.y - HEIGHT/2, 
            WIDTH, 
            HEIGHT
        };
        
        Rectangle cupBody = collider_;

        DrawRectangle(cupBody.x, cupBody.y, cupBody.width, cupBody.height, GRAY);
        DrawRectangleLines(cupBody.x, cupBody.y, cupBody.width, cupBody.height, BLACK);
        
        Rectangle handle = {
            position_.x - WIDTH * 0.70f, 
            position_.y - 20, 
            8, 
            35
        };
        DrawRectangleLines(handle.x, handle.y, handle.width, handle.height, BLACK);
    }

    void Cup::Floating(bool isJetpackActive)
    {
        float dt = GetFrameTime();

        if (isJetpackActive) {
            velocityY_ += LIFT * dt;
        } else {
            velocityY_ += GRAVITY * dt;
        }

        position_.y += velocityY_ * dt;

        // Batas atas & bawah
        if (position_.y < MAX_HEIGHT) {
            position_.y = MAX_HEIGHT;
            velocityY_ = 0;
        } else if (position_.y > GROUND_Y) {
            position_.y = GROUND_Y;
            velocityY_ = 0;
        }
    }

    void Cup::MoveAside()
    {
        float dt = GetFrameTime();
        position_.x += 220.0 * dt;
    }
    
    Vector2 Cup::GetPosition() const {
        return position_;
    }

    void Cup::SetPosition(Vector2 pos){
        position_ = pos;
    }

    Rectangle* Cup::GetCollider()
    {
        return &collider_;
    }
}