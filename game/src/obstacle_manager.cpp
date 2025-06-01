#include "obstacle_manager.h"

namespace UpperCup::Game
{
    void ObstacleManager::CreateObstacle()
    {
        obstacles_.clear();

        for(int i = 0; i < obs_init_.size(); i++) {
            Vector2 pos;
            if(i == 0) {
                pos = {GetScreenWidth() + obs_init_[i].pos.x, obs_init_[i].pos.y};
            } else {
                Vector2 prevPos = obstacles_[i - 1]->GetPosition();
                pos = {prevPos.x + obs_init_[i].dist, obs_init_[i].pos.y};
            }

            auto obs = Factories::ObstacleFactory::CreateObstacle(pos, obs_init_[i].length, obs_init_[i].dist);
            obstacles_.push_back(obs);
        }
    }

    void ObstacleManager::RenderObstacles()
    {
        if(obstacles_.empty()) return;

        for(auto obj : obstacles_)
        {
            obj->Render();
        }
    }

    void ObstacleManager::CycleObstalce(float cameraX) {
        if (obstacles_.empty()) return;

        int obs_size = obstacles_.size();

        for (int i = 0; i < obs_size; i++) {
            if (obstacles_[i]->GetPosition().x + 20 < cameraX - 100) {
                int behind = (obs_size + (i-1)) % obs_size;
                float x = obstacles_[behind]->GetPosition().x;

                obstacles_[i]->SetPositionBehindX(x);
            }
        }
}

    bool ObstacleManager::IsCollide(Rectangle &other)
    {
        for(auto obj : obstacles_)
        {
            if(obj->CheckCollision(other)) return true;
        }

        return false;
    }
}
