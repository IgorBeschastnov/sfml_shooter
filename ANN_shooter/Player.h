#pragma once
#include "Soldier.h"
class Player :
	public Soldier
{
private:
	Vector2f getMoveDirection();
	Vector2f getLookDirection();
	const RenderWindow* window;
	void Calculate() override;
public:
	Player(Animation, Weapon, float, Field&, Vector2f);
	Player(Animation, Animation, Animation, Animation, Weapon, float, Field&, Vector2f);
	~Player();
};

