#pragma once
#include "Entity.h"

class Zombie : public Entity
{
private:
	float maxHp, hp;
public:
	Zombie(float maxHp = 10, float hp = 10, int speed = 50.f);
	~Zombie();

	void OnUpdate() override;

	void TakeDamage(float amount);

	void RemoveZombie();
};
