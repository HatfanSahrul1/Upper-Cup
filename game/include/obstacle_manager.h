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
            void CycleObstalce(float cameraX);

            bool IsCollide(Rectangle &other);

        private:
            std::vector<ObstacleProp> obs_init_ = {
                {{400, 200},        300, 700},
                {{400, 400},        100, 500},
                {{400, 100},        250, 380},
                {{400, 300},        100, 420},
                {{400, 200},        180, 350},
                {{400, 250},        220, 390},
                {{400, 150},        230, 410},
                {{400, 320},        170, 370},
                {{400, 250},        210, 430},
                {{400, 280},        190, 400},
                {{400, 350},        155, 360},
                {{400, 350},        160, 440},
                {{400, 280},        220, 380},
                {{400, 220},        200, 450},
                {{400, 295},        230, 420},
                {{400, 230},        180, 390},
                {{400, 270},        210, 410},
                {{400, 310},        190, 400}
            };

            std::vector<std::shared_ptr<Objects::Obstacle>> obstacles_;
    };
}