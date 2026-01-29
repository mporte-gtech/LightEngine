#include "Projectile.h"

Projectile::Projectile(float speed, float dmg) :
	dmg(dmg)
{
	mSpeed = speed;
}

void Projectile::OnUpdate()
{
	GoToDirection(GetPosition().x + mSpeed, GetPosition().y, mSpeed);
}

void Projectile::setDmg(float newDmg)
{
	dmg = newDmg;
}
