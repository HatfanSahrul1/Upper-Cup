#pragma once

#include <iostream>
#include <memory>
#include "objects.h"
#include <stdexcept>

namespace UpperCup::Factories
{
    class CupFactory
    {
        public:
            static std::shared_ptr<UpperCup::Objects::Cup> CreateCup(Vector2 position)
            {
                auto cup = std::make_shared<UpperCup::Objects::Cup>(position);
                return cup;
            }
    };

    class ObstacleFactory
    {
        public:
            static std::shared_ptr<UpperCup::Objects::Obstacle> CreateObstacle(Vector2 initPos, float length, float distance)
            {
                auto obstacle = std::make_shared<UpperCup::Objects::Obstacle>(initPos, length, distance);
                return obstacle;
            }  
    };

    class WallFactory
    {
        public:
            static std::shared_ptr<UpperCup::Objects::Wall> CreateWall(const std::string& type, float screenHeight)
            {
                if (type == "top") {
                    Vector2 position = {0, 0}; 
                    float height = 30.0f;
                    auto wall = std::make_shared<UpperCup::Objects::Wall>(position, height);
                    return wall;
                }
                else if (type == "bottom") {
                    float groundHeight = 50.0f;
                    Vector2 position = {0, screenHeight - groundHeight};
                    auto wall = std::make_shared<UpperCup::Objects::Wall>(position, groundHeight);
                    return wall;
                }
                else {
                    throw std::invalid_argument("Invalid wall type: " + type);
                }
            }
    };
}
