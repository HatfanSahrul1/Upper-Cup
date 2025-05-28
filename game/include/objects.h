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
            Cup(Vector2 startPos);

            void Render() override;

            void Floating(bool isJetpackActive);
            Vector2 GetPosition() const;

        private:
            Vector2 position;
            float velocityY = 0.0f;

            const float gravity     = 500.0f;
            const float lift        = -600.0f;
            const float maxHeight   = 50.0f;
            const float groundY     = 500.0f;
            const float width       = 40.0f;
            const float height      = 60.0f;
    };

    class Obstacle : public Renderable
    {
        public:
    };
}