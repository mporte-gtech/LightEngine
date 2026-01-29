#pragma once
#include "StateBase.h"

class Plant;

class StateShootingPlant : public StateBase<Plant>
{
private:
	float cooldown;

public:
	void Start(Plant* classPointer) override;

	void Update(Plant* classPointer, float deltaTime) override;

	void End(Plant* classPointer) override;

	bool CanTransitionFrom(Plant* classPointer, int currentState) override;
};
