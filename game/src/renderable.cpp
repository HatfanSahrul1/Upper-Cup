#include "objects.h"

namespace UpperCup::Objects
{
    std::vector<Renderable*> RenderableObjects;

    Renderable::Renderable()
    {
        AssignObject();
    }

    void Renderable::AssignObject(){
        RenderableObjects.push_back(this);
    }
}