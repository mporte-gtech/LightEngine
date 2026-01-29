#include "Zombie.h"
#include <iostream>

Zombie::Zombie(float maxHp, float hp, int speed) :
	maxHp(maxHp), hp(hp)
{
	mSpeed = speed;
}

void Zombie::OnUpdate()
{
	GoToDirection(GetPosition().x - mSpeed, GetPosition().y, mSpeed);
}

void Zombie::TakeDamage(float amount)
{
	hp = std::fmax(0.f, hp - amount);
}
