#pragma once
#include "StateBase.h"
#include <string>

class Plant;

class StateReloadingPlant : public StateBase<Plant>
{
private:
	float cooldown;

public:
	std::string GetStateName() override;

	void Start(Plant* classPointer) override;

	void Update(Plant* classPointer, float deltaTime) override;

	void End(Plant* classPointer) override;

	bool CanTransitionFrom(Plant* classPointer, int currentState) override;
};
