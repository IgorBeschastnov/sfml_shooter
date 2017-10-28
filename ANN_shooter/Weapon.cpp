#include "Weapon.h"

void Weapon::Shoot(Vector2f direction, Vector2f position)
{
	if (CLOCK.getElapsedTime().asSeconds() - lastTime > (1/shootSpeed))
	{
		enemyProjectiles.emplace_back(projectile);
		enemyProjectiles.back().Shoot(direction, position);
		lastTime = CLOCK.getElapsedTime().asSeconds();
	}
}

Weapon::Weapon(Projectile projectile_, int damage_, float projectileSpeed_, float shootSpeed_) : projectile(projectile_)
{
	lastTime = CLOCK.getElapsedTime().asSeconds();
	damage = damage_;
	projectileSpeed = projectileSpeed_;
	shootSpeed = shootSpeed_;
	projectile.damage = damage;
	projectile.speed = projectileSpeed;
}


Weapon::~Weapon()
{
}
