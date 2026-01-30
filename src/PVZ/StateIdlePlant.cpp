#include "StateIdlePlant.h"
#include "Plant.h"

std::string StateIdlePlant::GetStateName()
{
	return "Idle";
}

void StateIdlePlant::Start(Plant* classPointer)
{
}

void StateIdlePlant::Update(Plant* classPointer, float deltaTime)
{
}

void StateIdlePlant::End(Plant* classPointer)
{
}

bool StateIdlePlant::CanTransitionFrom(Plant* classPointer, int currentState)
{
	switch ((Plant::States)currentState)
	{
	case Plant::States::Idle:
		return false;
	}

	return true;
}
