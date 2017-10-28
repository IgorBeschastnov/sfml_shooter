#pragma once
#include "WorldConstants.h"
#include "Projectile.h"
#include "General.h"
class Weapon
{
protected:
	Projectile projectile;
	int damage;
	float projectileSpeed;
	float shootSpeed;
	float lastTime;
public:
	virtual void Shoot(Vector2f, Vector2f);
	Weapon(Projectile, int, float, float);
	~Weapon();
};

