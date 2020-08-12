#pragma once

#include "resource_identifiers.hpp"
#include "enemies/enemy.hpp"
#include "tower.hpp"
#include "bullet.hpp"

#include <vector>

struct Direction
{
	Direction(float angle, float distance)
	: angle(angle)
	, distance(distance)
	{
	}

	float angle;
	float distance;
};

//hitpoints and speed are in datatable and enemy class, check if this is necessary
struct EnemyData
{
	int				hitpoints;
	float			speed;
	Textures::ID	texture;
};

//initializer
std::vector<EnemyData>	InitializeEnemyData();
std::vector<Direction>	InitializeEnemyPath();

struct TowerData {
	Textures::ID	texture;
    float 			range;
    float 			reloadTime;
    int 			bulletType;
};

//initializer
std::vector<TowerData>	InitializeTowerData();

struct BulletData {
    float           speed;
    int             damage;
    int             damageDuration;
};

//initializer
std::vector<BulletData>	InitializeBulletData();
