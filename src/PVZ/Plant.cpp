#include "Plant.h"
#include "Projectile.h"
#include "StateIdlePlant.h"
#include "StateShootingPlant.h"
#include "StateReloadingPlant.h"
#include <iostream>

Plant::Plant(int magazineSize, int ammos, float empoweredShot, float empoweredShotReload) :
	magazineSize(magazineSize), ammos(ammos), empoweredShot(empoweredShot), empoweredShotReload(empoweredShotReload)
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

void Plant::ShootSuper()
{
	if (empoweredShotReload <= 0)
	{
		Projectile* temp = GetScene()->CreateEntity<Projectile>(5, sf::Color::White);
		temp->SetPosition(GetPosition().x, GetPosition().y);
		temp->setDmg(8);

		empoweredShotReload = empoweredShot;
	}
}

void Plant::OnUpdate()
{
	stateMachine->TryChangeState(this, (int)States::Shooting);

	empoweredShotReload = fmax(0, empoweredShotReload -= GetDeltaTime());
}
