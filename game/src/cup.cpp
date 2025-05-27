#include "objects.h"

namespace UpperCup::Objects
{
    void Cup::Render()
    {
        DrawRectangleV(position, {width, height}, DARKBLUE);

        Vector2 handlePos = {position.x + width, position.y + height / 4};
        DrawCircleV(handlePos, height / 4, BLUE);
    }
}