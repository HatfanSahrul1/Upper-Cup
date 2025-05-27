#include "objects.h"

namespace UpperCup::Objects
{
    static std::vector<Renderable*> RenderableObjects;

    void Renderable::AssignObject(){
        RenderableObjects.push_back(this);
    }
}