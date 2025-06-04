#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"
#include "math.h"

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

    struct ShatterPiece {
        Vector2 position;
        Vector2 velocity;
        float size;
    };

    class Cup : public Renderable
    {
        public:
            Cup() : Cup({0, 0}) {}
            Cup(Vector2 startPos);
            ~Cup();

            void Render() override;

            void Floating(bool isJetpackActive);
            void MoveAside();
            Vector2 GetPosition() const;
            Rectangle* GetCollider();
            void SetPosition(Vector2 pos);
        private:
            Vector2 position_;
            float velocityY_ = 0.0f;
            Rectangle collider_;

            Texture2D cupTexture_;

            const float GRAVITY     = 500.0f;
            const float LIFT        = -600.0f;
            const float MAX_HEIGHT  = 50.0f;
            const float GROUND_Y    = 520.0f;
            const float WIDTH       = 40.0f;
            const float HEIGHT      = 60.0f;
    };

    class Obstacle : public Renderable
    {
        public:
            Obstacle() : Obstacle({0, 0}, 100, 100) {}
            Obstacle(Vector2 initPos, float length, float distance);

            void Render() override;

            void Move(float deltaTime);

            Vector2 GetPosition();
            void SetPositionBehindX(float newX);

            std::vector<Rectangle> GetColliders();
            bool CheckCollision(Rectangle &other);
        private:
            const float SIZE = 20;

            Vector2 headPosition_;
            float length_;
            float distance_;

    };

    class Wall : public Renderable
    {
        public:
            Wall() : Wall({0, 0}, 50) {}
            Wall(Vector2 pos, float height);

            void Render() override;

        private:
            Vector2 position_;
            float height_;
            
            const float WIDTH = 1000;

    };
}