#include "enemy.hpp"
#include "../utility.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <iostream> //For initial debugging
#include <cmath>

// Associates enemies with the corresponding textures
// Textures are images that live on the graphics card

namespace
{
	const std::vector<EnemyData> Table = InitializeEnemyData();
    const std::vector<Direction> Path = InitializeEnemyPath();
}

// Constructor
Enemy::Enemy(Enemy::Type type, const TextureHolder& textures, unsigned int difficultyLevel, float travelledDistance, int directionIndex)
    : Entity(Table[type].hitpoints),
        type_(type), 
        sprite_(textures.Get(Textures::ID::NoTexture)),
        travelledDistance_(travelledDistance), 
        totalTravelledDistance_(0),
        directionIndex_(directionIndex),
        difficultyLevel_(difficultyLevel),
        difficultyIncrement_(0.25), 
        maxSpeed_(Table[type].speed),
        isSlowedDown_(false),
        slowDownRate_(Table[type].slowDownRate), 
        isMarkedForRemoval_(false),
        showDeathAnimation_(true),
        hasMovementAnimation_(false),
        deathAnimation_(textures.Get(Textures::DeathAnimation)),
        movementAnimation_(),
        isGivenMoney_(false)
    { 
        // initializing totalTravelledDistance
        if (!Path.empty())
        {
            for (int i = 0; i < directionIndex; i++)
            {
                totalTravelledDistance_ += Path[i].distance;
            }
            totalTravelledDistance_ += travelledDistance;
        }
        
        sf::FloatRect bounds = sprite_.getLocalBounds();
        sprite_.setOrigin(bounds.width/2.f, bounds.height/2.f);

        deathAnimation_.SetFrameSize(sf::Vector2i(187, 201));
	    deathAnimation_.SetNumFrames(15);
	    deathAnimation_.SetDuration(sf::seconds(0.35));
    }

Enemy::~Enemy() {}

void Enemy::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const{
	if (IsDestroyed() && showDeathAnimation_)
		target.draw(deathAnimation_, states);
	else if (movementAnimation_.GetNumFrames() > 0)
		target.draw(movementAnimation_, states);
    else
        target.draw(sprite_, states);
}   

// returns Enemy category, but if enemy is destroyed returns None (0)
unsigned int Enemy::GetCategory() const 
{
    return Category::Enemy;
} 

// returns bounding rect of enemy node, used i.e. determining collisions between bullets and enemies
sf::FloatRect Enemy::GetBoundingRect() const
{
	return GetWorldTransform().transformRect(sprite_.getGlobalBounds());
}

// Enemy's speed increases by DifficultyCoefficient. If enemy is slowed down, speed is decreased 
float Enemy::GetSpeed() const
{
    if (isSlowedDown_)
    {
        return (1-slowDownRate_) * DifficultyCoefficient() * maxSpeed_; 
    } 
    return DifficultyCoefficient() * maxSpeed_;
}

// Slowing tower can make enemies to move slower
void Enemy::SlowDown() 
{
    isSlowedDown_ = true;
}

// flags if enemy can be removed from game field, initialized false
bool Enemy::IsMarkedForRemoval() const {
    return isMarkedForRemoval_;
}

// returns how much money enemy is worth, money can be gained from one enemy only once
int Enemy::GetMoney()
{
    if (isGivenMoney_)
    {
        return 0;
    }
    isGivenMoney_ = true;
    return Table[type_].worthOfMoney;
}

float Enemy::GetTravelledDistance()
{
    return totalTravelledDistance_;
}


//protected member functions

//Enemy movement pattern
void Enemy::UpdateMovementPattern(sf::Time dt)
{
	if (!Path.empty())
	{
		if (travelledDistance_ >= Path[directionIndex_].distance)
		{
			directionIndex_ = (directionIndex_ + 1) % Path.size(); 
			travelledDistance_ = 0.f;
            sprite_.setRotation(Path[directionIndex_].angle); //kääntää enemyn hitboxin animaation alla kun suuntaa muuttuu, jos rikkoo jotain ni pois vaan
		}
        
		float radians = ToRadian(Path[directionIndex_].angle); 
		float vx = GetSpeed() * std::cos(radians);
		float vy = GetSpeed() * std::sin(radians);

		SetVelocity(vx, vy);

		travelledDistance_ += GetSpeed() * dt.asSeconds();
        totalTravelledDistance_ += travelledDistance_;

        isSlowedDown_ = false; // if enemy was slowed down, return to not slowed down state
	}

} 

//Update the state of enemy
/* Possible cases:
* 1. enemy is alive (IsDestroyed() == false) 
*   - update movement animation and pattern (check if enemy needs to turn)
*   - run entity class' update
* 2. enemy is dead (hp <= 0)
*   - show deathanimation
*   - when animation is finished mark enemy for removal
*/
void Enemy::UpdateCurrent(sf::Time dt, CommandQueue& commands) {

    if (IsDestroyed())
	{
        deathAnimation_.Update(dt);
		if((deathAnimation_.IsFinished() || !showDeathAnimation_) && !CheckDestroyBehaviour(dt, commands)){
            isMarkedForRemoval_ = true;
        }
		return;
	}
    UpdateMovementAnimation(dt);
    UpdateMovementPattern(dt);
    Entity::UpdateCurrent(dt, commands); 
}


void Enemy::UpdateMovementAnimation(sf::Time dt){
    if(hasMovementAnimation_){
        movementAnimation_.Update(dt,Path[directionIndex_].angle);
    }
}

// Returns false if enemy has no ongoing destroy behaviour, and true if something is still happening
// used to determine if enemy can be marked for removal
// Enemy doesn't have any destroy behaviour by default
bool Enemy::CheckDestroyBehaviour(sf::Time, CommandQueue&)
{ 
    return false;
}

// Returns difficulty coefficient. Used for calculating enemy's speed, which increases as difficultyLevel increases
float Enemy::DifficultyCoefficient() const
{
    return 1 + (difficultyLevel_-1)*difficultyIncrement_;
}