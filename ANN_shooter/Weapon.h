#pragma once
#include "General.h"
#include "Object.h"
#include "Projectile.h"
class Soldier;
class Weapon
{
protected:
	Soldier* holder;
	Field** field;
	Projectile projectile;
	int damage;
	float projectileSpeed;
	float shootSpeed;
	float lastTime;
public:
	virtual void Shoot(Vector2f, Vector2f);
	Weapon(Projectile, int, float, float);
	Weapon(const Weapon&, Field**, Soldier*);
	~Weapon();
};

