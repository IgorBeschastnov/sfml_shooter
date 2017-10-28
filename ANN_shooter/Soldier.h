#pragma once
#include "Animation.h"
#include "Weapon.h"

enum StateSoldier
{
	idle = 0,
	walk,
	shoot,
	walkShoot
};

class Soldier
{
protected:
	Animation animations[4];
	Weapon weapon;
	StateSoldier state;
	SpriteList* list;
	Sprite sprite;
	Vector2f position;
	Vector2f rotation;
	float speed;
	void Time();
	float lastTime;
	float VectorToAngle(Vector2f);
public:
	void LookAt(Vector2f);
	void Move(Vector2f);
	void Shoot();
	virtual void Calculate();
	Soldier(Animation, Weapon, float);
	Soldier(Animation, Animation, Animation, Animation, Weapon, float);
	Sprite GetSprite();
	~Soldier();
};

