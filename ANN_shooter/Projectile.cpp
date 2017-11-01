#include "General.h"

void Projectile::Calculate()
{
	rotation = VectorOperations::ReductToLength(rotation, speed);
	//getting delta time
	float deltaTime = CLOCK.getElapsedTime().asSeconds() - lastTime;
	Vector2f bias = rotation*deltaTime;
	position += bias;
	sprite.setPosition(position);
	sprite.setTextureRect(animation.GetRect());
	Object::Calculate();
	Object::Resize();
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	lastTime = CLOCK.getElapsedTime().asSeconds();
}

Sprite Projectile::GetSprite()
{
	Calculate();
	return sprite;
}

void Projectile::Shoot(Vector2f direction_, Vector2f position_)
{
	rotation = direction_;
	position = position_;
	lastTime = CLOCK.getElapsedTime().asSeconds();
}

Projectile::Projectile(Animation animation_, Vector2f size_) : Object(Field(0,RenderWindow()),size_)
{
	animation = animation_;
	sprite.setTexture(animation.GetSpriteList()->atlas);
}

Projectile::Projectile(const Projectile & projectile, Field& field) : Object(field,projectile.size)
{
	speed = projectile.speed;
	animation = projectile.animation;
	damage = projectile.damage;
	sprite.setTexture(animation.GetSpriteList()->atlas);
}


Projectile::~Projectile()
{
	std::list<Projectile*>::iterator pos;
	int i = 0;
	for (; i < SoldierType::typesNumber; i++)
	{
		pos = std::find(globalProjectiles[i].begin(), globalProjectiles[i].end(), this);
		if (pos != globalProjectiles[i].end())
			break;
	}
	if (i != SoldierType::typesNumber)
	{
		std::cout << "Deleted" << std::endl;
		globalProjectiles[i].erase(pos);
	}
}
