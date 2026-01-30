#pragma once
#include "Entity.h"

class Projectile : public Entity
{
private:
	float dmg;
public:
	Projectile(float speed = 100.f, float dmg = 1.f);

	void OnUpdate() override;

	void OnCollision(Entity* other) override;

	void setDmg(float newDmg);
};
