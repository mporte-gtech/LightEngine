#pragma once

#include "Scene.h"
#include "Entity.h"
#include "Plant.h"
#include "Zombie.h"

class DummyEntity;

class PVZScene : public Scene
{
	std::vector<Plant*> plants;
	Plant* selectedPlant;

	std::vector<std::vector<Zombie*>> rows;
	int rowsAmount;

private:
	void TrySetSelectedPlant(Plant* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	bool AreZombiesInRow(int rowNumber);

	void RemovePlant(Plant* plantToRemove);
	void SpawnZombie(int rowNumber);
	void RemoveZombie(Zombie* zombieToRemove);
};
