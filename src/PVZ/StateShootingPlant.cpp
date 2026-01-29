#include "StateShootingPlant.h"
#include "Plant.h"
#include "Projectile.h"

void StateShootingPlant::Start(Plant* classPointer)
{
	Projectile* temp = classPointer->GetScene()->CreateEntity<Projectile>(5, sf::Color::White);
	temp->SetPosition(classPointer->GetPosition().x, classPointer->GetPosition().y);

	classPointer->ammos -= 1;

	cooldown = 0.5f;
}

void StateShootingPlant::Update(Plant* classPointer, float deltaTime)
{
	cooldown -= deltaTime;
}

void StateShootingPlant::End(Plant* classPointer)
{
}

bool StateShootingPlant::CanTransitionFrom(Plant* classPointer, int currentState)
{
	switch ((Plant::States)currentState)
	{
	case Plant::States::Idle:
		break;
	default:
		return false;
	}

	if (classPointer->ammos <= 0)
		return false;

	return true;
}
