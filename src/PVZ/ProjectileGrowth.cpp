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

	sf::CircleShape* shape = dynamic_cast<sf::CircleShape*>(GetShape());

	shape->setRadius(shape->getRadius() + 1.f * GetDeltaTime());

	dmg += 0.15 * GetDeltaTime();

	//GetShape()->setScale({ GetShape()->getScale().x + 0.1f,GetShape()->getScale().y + 0.1f});
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
