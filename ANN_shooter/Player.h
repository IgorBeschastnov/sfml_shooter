#pragma once
#include "Soldier.h"
class Player :
	public Soldier
{
private:
	Vector2f getMoveDirection();
	Vector2f getLookDirection();
	RenderWindow* window;
public:
	void Calculate() override;
	Player(Animation, Weapon, float, RenderWindow&);
	Player(Animation, Animation, Animation, Animation, Weapon, float, RenderWindow&);
	~Player();
};

