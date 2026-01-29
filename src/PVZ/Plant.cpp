#include "Plant.h"
#include "Projectile.h"
#include "StateIdlePlant.h"
#include "StateShootingPlant.h"
#include "StateReloadingPlant.h"

Plant::Plant(int magazineSize, int ammos) :
	magazineSize(magazineSize), ammos(ammos)
{
	stateMachine = new StateMachine<Plant>();

	stateMachine->AddState(new StateIdlePlant());
	stateMachine->AddState(new StateShootingPlant());
	stateMachine->AddState(new StateReloadingPlant());
}

void Plant::SetMagazineSize(int size)
{
	magazineSize = size;
}

void Plant::SetAmmos(int amount)
{
	ammos = amount;
}

void Plant::Shoot()
{
	stateMachine->TryChangeState(this, (int)States::Shooting);
}

void Plant::OnUpdate()
{
	stateMachine->TryChangeState(this, (int)States::Shooting);
}
