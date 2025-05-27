#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"

namespace UpperCup::Objects
{    
    class Renderable
    {
        public:
        virtual void Render() = 0;
        virtual ~Renderable() = default;
        
        virtual void AssignObject();
    };

    class Cup : public Renderable
    {
        public:
            Cup();

            void Render() override;

        private:
            Vector2 position;
            float width;
            float height;
    };
}