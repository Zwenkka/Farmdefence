#include "test_enemy.hpp"
#include "basic_enemy.hpp"
#include "../data_tables.hpp"
#include "../utility.hpp"

#include <iostream> //For initial debugging
#include <vector>


//Making a leaf type enemy as a test of derived class
TestEnemy::TestEnemy(const TextureHolder& textures, float difficultyLevel, float travelledDistance, int directionIndex)
    : Enemy(Enemy::Basic, textures, difficultyLevel, travelledDistance, directionIndex)
    { 
        showDeathAnimation_ = false;
        spawnFireEnemyCommand_.category_ = Category::Scene;
        spawnFireEnemyCommand_.action_ = [this, &textures] (SceneNode& node, sf::Time) 
        {
            //std::cout <<"spawning a new enemy" << std::endl;
            std::unique_ptr<Enemy> newEnemy(new BasicEnemy(textures, difficultyLevel_, travelledDistance_, directionIndex_));
		    newEnemy->setPosition(this->GetWorldPosition());
            //newEnemy->setScale(0.25f, 0.25f);
		    newEnemy->SetVelocity( UnitVector(this->GetVelocity()) * newEnemy->GetSpeed() ); 
		    node.AttachChild(std::move(newEnemy));
        };
    }


bool TestEnemy::CheckDestroyBehaviour(sf::Time, CommandQueue& commands)
{
    //std::cout << "hello from here" << std::endl;
    commands.Push(spawnFireEnemyCommand_);
}
