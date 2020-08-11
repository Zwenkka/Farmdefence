#pragma once

#include "enemy.hpp"
#include "../command_queue.hpp"

class TestEnemy : public Enemy {

    public:
        TestEnemy(const TextureHolder &textures, float travelledDistance = 0.f, int directionIndex = 0, float difficultyLevel = 1.f);
        //~TestEnemy();
            
        //bool IsMarkedForRemoval() const override;

    private:
        void CheckDestroyBehaviour(CommandQueue& commands) override;
        void UpdateMovementPattern(sf::Time dt) override;
 
        Command spawnFireEnemyCommand_;
};

