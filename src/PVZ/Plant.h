#pragma once
#include "Entity.h"
#include "StateMachine.h"

class Plant : public Entity
{
	friend class StateIdlePlant;
	friend class StateShootingPlant;
	friend class StateReloadingPlant;

protected:

	enum class States
	{
		Idle,
		Shooting,
		Reloading,

		Count
	};

private:
	int magazineSize, ammos;

	StateMachine<Plant>* stateMachine;
public:
	Plant(int magazineSize = 5, int ammos = 5);

	void SetMagazineSize(int size);

	void SetAmmos(int amount);

	void Shoot();

	void OnUpdate() override;
};
