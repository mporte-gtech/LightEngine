#include "Zombie.h"
#include <iostream>
#include "PVZScene.h"

Zombie::Zombie(float maxHp, float hp, int speed) :
	maxHp(maxHp), hp(hp)
{
	mSpeed = speed;
}

Zombie::~Zombie()
{
	Destroy();
}

void Zombie::OnUpdate()
{
	GoToDirection(GetPosition().x - mSpeed, GetPosition().y, mSpeed);
}

void Zombie::TakeDamage(float amount)
{
	hp = std::fmax(0.f, hp - amount);

	if (hp <= 0)
	{
		PVZScene* scene;
		if ((scene = dynamic_cast<PVZScene*>(GetScene())) != nullptr)
			scene->RemoveZombie(this);
		Destroy();
	}
}
