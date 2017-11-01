#include "Weapon.h"

Weapon::Weapon(Projectile projectile_, int damage_, float projectileSpeed_, float shootSpeed_) : projectile(projectile_)
{
	lastTime = CLOCK.getElapsedTime().asSeconds();
	damage = damage_;
	projectileSpeed = projectileSpeed_;
	shootSpeed = shootSpeed_;
	projectile.damage = damage;
	projectile.speed = projectileSpeed;
	field = nullptr;
}

Weapon::Weapon(const Weapon& weapon, Field** field_, Soldier* holder_) : projectile(weapon.projectile)
{
	holder = holder_;
	lastTime = CLOCK.getElapsedTime().asSeconds();
	damage = weapon.damage;
	projectileSpeed = weapon.projectileSpeed;
	shootSpeed = weapon.shootSpeed;
	projectile.damage = damage;
	projectile.speed = projectileSpeed;
	field = field_;
}


Weapon::~Weapon()
{
}
