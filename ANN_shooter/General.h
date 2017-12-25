#pragma once
#include "VectorOperations.h"
#include "WorldConstants.h"
#include "Projectile.h"
enum SoldierType
{
	player = 0,
	enemy,
	typesNumber
};

enum StateSoldier
{
	idle = 0,
	walk,
	shoot,
	walkShoot
};

extern std::vector<std::list<Projectile*>> globalProjectiles;