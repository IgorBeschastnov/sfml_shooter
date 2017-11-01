#pragma once
#include "Animation.h"
#include "Weapon.h"
#include "Object.h"

class Soldier :
	public Object
{
protected:
	SoldierType type;
	Animation animations[4];
	Weapon weapon;
	StateSoldier state;
	SpriteList* list;
	float speed;
	void Time();
	float lastTime;
	float VectorToAngle(Vector2f);
public:
	void LookAt(Vector2f);
	void Move(Vector2f);
	void Shoot();
	SoldierType GetType();
	virtual void Calculate();
	Soldier(Animation, Weapon, float, Field&, Vector2f);
	Soldier(Animation, Animation, Animation, Animation, Weapon, float, Field&, Vector2f);
	Sprite GetSprite() override;
	~Soldier();
};

