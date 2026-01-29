#include "Projectile.h"
#include "Zombie.h"
#include <iostream>

Projectile::Projectile(float speed, float dmg) :
	dmg(dmg)
{
	mSpeed = speed;
}

void Projectile::OnUpdate()
{
	GoToDirection(GetPosition().x + mSpeed, GetPosition().y, mSpeed);
}

void Projectile::OnCollision(Entity* other)
{
	Zombie* zombie;
	if ((zombie = dynamic_cast<Zombie*>(other)) != nullptr)
	{
		zombie->TakeDamage(dmg);

		Destroy();
	}
}

void Projectile::setDmg(float newDmg)
{
	dmg = newDmg;
}
