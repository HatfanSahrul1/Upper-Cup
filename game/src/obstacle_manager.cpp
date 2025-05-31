#include "obstacle_manager.h"

namespace UpperCup::Game
{
    void ObstacleManager::CreateObstacle()
    {
        obstacles_.clear();

        for(int i = 0; i < obs_init_.size(); i ++){
            if(i == 0){
                Vector2 pos = {GetScreenWidth() + obs_init_[i].pos.x, obs_init_[i].pos.y};
                auto obs = Factories::ObstacleFactory::CreateObstacle(pos, obs_init_[i].length, obs_init_[i].dist);
                obstacles_.push_back(obs);
            }
            else
            {
                Vector2 pos = {obs_init_[i].dist + obs_init_[i-1].pos.x, obs_init_[i].pos.y};
                auto obs = Factories::ObstacleFactory::CreateObstacle(pos, obs_init_[i].length, obs_init_[i].dist);
                obstacles_.push_back(obs);
            }
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

    bool ObstacleManager::IsCollide(Rectangle &other)
    {
        for(auto obj : obstacles_)
        {
            if(obj->CheckCollision(other)) return true;
        }

        return false;
    }
}
