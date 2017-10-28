#pragma once
#include "WorldConstants.h"
#include "Animation.h"
#include "VectorOperations.h"
class Projectile
{
	friend class Weapon;
protected:
	Sprite sprite;
	Animation animation;
	float speed;
	int damage;
	Vector2f position;
	Vector2f direction;
	float lastTime;
public:
	virtual void Calculate();
	Sprite GetSprite();
	void Shoot(Vector2f, Vector2f);
	Projectile(Animation);
	Projectile(const Projectile&);
	~Projectile();
};

