#include "Soldier.h"

void Soldier::LookAt(Vector2f lookDirection)
{
	rotation = lookDirection;
	sprite.setRotation(VectorOperations::VectorToRotation(lookDirection));
}

void Soldier::Move(Vector2f direction)
{
	direction = VectorOperations::ReductToLength(direction, speed);
	//getting delta time
	float deltaTime = CLOCK.getElapsedTime().asSeconds() - lastTime;
	//modifying state
	if (state == shoot)
		state = walkShoot;
	if (state == idle)
		state = walk;
	//calculating bias
	Vector2f bias = direction*deltaTime;
	//modifying position
	position += bias;
	//DEBUG LINE std::cout << sqrt(bias.x*bias.x + bias.y*bias.y) << std::endl;
}

void Soldier::Time()
{
	lastTime = CLOCK.getElapsedTime().asSeconds();
}

float Soldier::VectorToAngle(Vector2f direction)
{
	return 0.0f;
}

void Soldier::Shoot()
{
	if (state == idle)
		state = shoot;
	if (state == walk)
		state = walkShoot;
	weapon.Shoot(rotation, position);
}

SoldierType Soldier::GetType()
{
	return type;
}

void Soldier::Calculate()
{
	sprite.setTextureRect(animations[state].GetRect());
	Object::Calculate();
	Object::Resize();
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	Time();
}

Soldier::Soldier(Animation defaultAnimation, Weapon weapon_, float speed_, Field& field_, Vector2f size) : Object(field_, size), weapon(weapon_,&field, this)
{
	type = enemy;
	speed = speed_;
	list = defaultAnimation.GetSpriteList();
	sprite.setTexture(list->atlas);
	animations[0] = defaultAnimation;
	animations[1] = defaultAnimation;
	animations[2] = defaultAnimation;
	animations[3] = defaultAnimation;
}

Soldier::Soldier(Animation idle_, Animation walk_, Animation shoot_, Animation walkShoot_, Weapon weapon_, float speed_, Field& field_, Vector2f size) : Object(field_, size), weapon(weapon_, &field, this)
{
	type = enemy;
	speed = speed_;
	list = idle_.GetSpriteList();
	sprite.setTexture(list->atlas);
	animations[0] = idle_;
	animations[1] = walk_;
	animations[2] = shoot_;
	animations[3] = walkShoot_;
}

Sprite Soldier::GetSprite()
{
	Calculate();
	return sprite;
}


Soldier::~Soldier()
{
}

void Weapon::Shoot(Vector2f direction, Vector2f position)
{
	if (*field != nullptr)
	{
		if (CLOCK.getElapsedTime().asSeconds() - lastTime > (1 / shootSpeed))
		{
			Projectile* prj = new Projectile(projectile, **field);
			globalProjectiles[holder->GetType()].push_back(prj);
			globalProjectiles[holder->GetType()].back()->Shoot(direction, position);
			lastTime = CLOCK.getElapsedTime().asSeconds();
		}
	}
}
