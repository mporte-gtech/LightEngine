#include "Plant.h"
#include "Projectile.h"
#include "StateIdlePlant.h"
#include "StateShootingPlant.h"
#include "StateReloadingPlant.h"
#include "PVZScene.h"
#include <iostream>

Plant::Plant(int row, int magazineSize, int ammos, float empoweredShot, float empoweredShotReload) :
	rowNumber(row), magazineSize(magazineSize), ammos(ammos), empoweredShot(empoweredShot), empoweredShotReload(empoweredShotReload)
{
	stateMachine = new StateMachine<Plant>();

	stateMachine->AddState(new StateIdlePlant());
	stateMachine->AddState(new StateShootingPlant());
	stateMachine->AddState(new StateReloadingPlant());

	stateMachine->TryChangeState(this, (int)States::Idle);
}

Plant::~Plant()
{
	Destroy();
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

void Plant::SetRowNumber(int newRow)
{
	rowNumber = newRow;
}

int Plant::GetRowNumber()
{
	return rowNumber;
}

void Plant::OnUpdate()
{
	stateMachine->Update(this, GetDeltaTime());

	empoweredShotReload = fmax(0, empoweredShotReload -= GetDeltaTime());

	bool ShouldShoot = dynamic_cast<PVZScene*>(GetScene())->AreZombiesInRow(rowNumber) == true;

	if (ammos <= 0 || (!ShouldShoot && ammos < magazineSize))
		stateMachine->TryChangeState(this, (int)States::Reloading);
	else if (ShouldShoot)
		stateMachine->TryChangeState(this, (int)States::Shooting);
}
