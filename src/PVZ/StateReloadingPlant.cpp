#include "StateReloadingPlant.h"
#include "Plant.h"

void StateReloadingPlant::Start(Plant* classPointer)
{
	cooldown = 2.5f;
}

void StateReloadingPlant::Update(Plant* classPointer, float deltaTime)
{
}

void StateReloadingPlant::End(Plant* classPointer)
{
	classPointer->ammos = classPointer->magazineSize;
}

bool StateReloadingPlant::CanTransitionFrom(Plant* classPointer, int currentState)
{
	switch ((Plant::States)currentState)
	{
	case Plant::States::Idle:
		break;
	default:
		return false;
	}

	if (classPointer->ammos >= classPointer->magazineSize)
		return false;

	return true;
}
