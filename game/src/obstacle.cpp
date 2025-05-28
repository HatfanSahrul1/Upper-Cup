#include "objects.h"

namespace UpperCup::Objects
{
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
}