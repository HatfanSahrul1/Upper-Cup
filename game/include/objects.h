#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"

namespace UpperCup::Objects
{    
    class Renderable
    {
        public:
            Renderable();
            
        virtual void Render() = 0;
        virtual ~Renderable() = default;
        
        virtual void AssignObject();

    };

    extern std::vector<Renderable*> RenderableObjects;

    class Cup : public Renderable
    {
        public:
            Cup(Vector2 startPos);

            void Render() override;

            void Floating(bool isJetpackActive);
            Vector2 GetPosition() const;

        private:
            Vector2 position_;
            float velocityY_ = 0.0f;

            const float GRAVITY     = 500.0f;
            const float LIFT        = -600.0f;
            const float MAX_HEIGHT  = 50.0f;
            const float GROUND_Y    = 500.0f;
            const float WIDTH       = 40.0f;
            const float HEIGHT      = 60.0f;
    };

    class Obstacle : public Renderable
    {
        public:
    };
}