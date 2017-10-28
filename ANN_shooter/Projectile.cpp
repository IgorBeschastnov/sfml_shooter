#include "Projectile.h"

void Projectile::Calculate()
{
	direction = VectorOperations::ReductToLength(direction, speed);
	//getting delta time
	float deltaTime = CLOCK.getElapsedTime().asSeconds() - lastTime;
	Vector2f bias = direction*deltaTime;
	position += bias;
	sprite.setPosition(position);
	sprite.setTextureRect(animation.GetRect());
	lastTime = CLOCK.getElapsedTime().asSeconds();
}

Sprite Projectile::GetSprite()
{
	return sprite;
}

void Projectile::Shoot(Vector2f direction_, Vector2f position_)
{
	direction = direction_;
	position = position_;
	lastTime = CLOCK.getElapsedTime().asSeconds();
}

Projectile::Projectile(Animation animation_)
{
	animation = animation_;
	sprite.setTexture(animation.GetSpriteList()->atlas);
}

Projectile::Projectile(const Projectile & projectile)
{
	speed = projectile.speed;
	animation = projectile.animation;
	damage = projectile.damage;
	sprite.setTexture(animation.GetSpriteList()->atlas);
}


Projectile::~Projectile()
{
}
