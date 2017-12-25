#pragma once
#include "WorldConstants.h"
#include "Animation.h"
#include "VectorOperations.h"
#include "Object.h"
class Projectile :
	public Object
{
	friend class Perceptor;//DEBUG
	friend class Weapon;
protected:
	Animation animation;
	float speed;
	int damage;
	float lastTime;
public:
	virtual void Calculate() override;
	Sprite GetSprite() override;
	void Shoot(Vector2f, Vector2f);
	Projectile(Animation, Vector2f);
	Projectile(const Projectile&, Field&);
	~Projectile();
};

