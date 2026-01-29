#include "Projectile.h"

Projectile::Projectile(float speed)
{
	mSpeed = speed;
}

void Projectile::OnUpdate()
{
	GoToDirection(1, GetPosition().y, mSpeed);
}
