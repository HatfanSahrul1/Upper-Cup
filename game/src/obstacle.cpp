#include "objects.h"

namespace UpperCup::Objects
{
    #pragma region Obstacle
    Obstacle::Obstacle(Vector2 initPos, float length, float distance)
    : headPosition_(initPos), length_(length), distance_(distance)
    {}

    void Obstacle::Render(){
        DrawRectangle(headPosition_.x, headPosition_.y, SIZE, SIZE, BLACK);
        
        DrawRectangle(headPosition_.x, headPosition_.y + length_, SIZE, SIZE, BLACK);

        DrawLineEx(
            {headPosition_.x + SIZE/2, headPosition_.y + SIZE/2}, 
            {headPosition_.x + SIZE/2, (headPosition_.y + SIZE/2)+length_},
            3,
            RED
        );
    }

    void Obstacle::Move(float deltaTime)
    {
        headPosition_.x -= 220.0 * deltaTime;
    }

    std::vector<Rectangle> Obstacle::GetColliders() {
        std::vector<Rectangle> colliders;

        Rectangle topBox = {
            headPosition_.x,
            headPosition_.y,
            SIZE,
            SIZE
        };
        colliders.push_back(topBox);

        Rectangle bottomBox = {
            headPosition_.x,
            headPosition_.y + length_,
            SIZE,
            SIZE
        };
        colliders.push_back(bottomBox);

        Rectangle middleLine = {
            headPosition_.x + SIZE / 2 - 1.5f, 
            headPosition_.y + SIZE,
            3.0f,
            length_ - SIZE
        };
        colliders.push_back(middleLine);

        return colliders;
    }

    bool Obstacle::CheckCollision(Rectangle &other)
    {
        for(auto rect : this->GetColliders())
        {
            if(CheckCollisionRecs(rect, other)) return true;
        }

        return false;
    }

    Vector2 Obstacle::GetPosition()
    {
        return headPosition_;
    }

    void Obstacle::SetPositionBehindX(float newX)
    {
        headPosition_.x = newX + distance_;
    }
    #pragma endregion

    #pragma region Wall
    Wall::Wall(Vector2 pos, float height)
    : position_(pos), height_(height)
    {}

    void Wall::Render()
    {
        DrawRectangle(position_.x, position_.y, WIDTH,  height_, BLACK);
    }
    #pragma endregion
}