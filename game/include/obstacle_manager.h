#pragma once

#include <memory>
#include "objects.h"
#include "factories.h"

using namespace UpperCup;

namespace UpperCup::Game
{
    struct ObstacleProp
    {
        Vector2 pos;
        int length;
        int dist;
    };
    
    class ObstacleManager
    {
        public:
            void CreateObstacle();
            void RenderObstacles();

        private:
            std::vector<ObstacleProp> obs_init_ = {
                {{400, 200}, 300, 700},
                {{400, 400}, 100, 500}
            };

            std::vector<std::shared_ptr<Objects::Obstacle>> obstacles_;
    };
}