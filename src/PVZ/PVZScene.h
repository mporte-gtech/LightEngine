#pragma once

#include "Scene.h"
#include "Entity.h"
#include "Plant.h"
#include "Zombie.h"

class DummyEntity;

class SampleScene : public Scene
{
	std::vector<std::vector<Plant*>> plants;
	Plant* selectedPlant;

	std::vector<std::vector<Zombie*>> zones;

	int rowsAmount;

private:
	void TrySetSelectedPlant(Plant* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};
