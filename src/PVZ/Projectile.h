#pragma once
#include "Entity.h"

class Projectile : public Entity
{
public:
	Projectile(float speed = 10.f);

	void OnUpdate() override;
};
