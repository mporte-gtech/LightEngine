#include "PVZScene.h"

#include "Plant.h"
#include "Zombie.h"
#include "Projectile.h"

#include "Debug.h"
#include <iostream>
#include <vector>

void PVZScene::OnInitialize()
{
	rowsAmount = 3;

	for (int i = 0; i < rowsAmount; i++)
	{
		Plant* temp = CreateEntity<Plant>(50, sf::Color::Green);

		temp->SetPosition(temp->GetRadius() + 10, i * (GetWindowHeight() / rowsAmount) + (GetWindowHeight() / (rowsAmount * 2)));
		temp->SetRowNumber(i);

		plants.push_back(temp);
		rows.push_back(std::vector<Zombie*>());
	}

	selectedPlant = nullptr;
}

void PVZScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed && event.type != sf::Event::EventType::KeyPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		for (int i = 1; i <= rowsAmount; i++)
		{
			float laneHeight = GetWindowHeight() / rowsAmount;

			if (event.mouseButton.y < laneHeight * i)
			{
				Zombie* temp = CreateEntity<Zombie>(50, sf::Color::Red);
				temp->SetPosition(event.mouseButton.x, laneHeight * i - laneHeight / 2);
				temp->SetSpeed(50);

				rows[i - 1].push_back(temp);

				break;
			}
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		for (Plant* plant : plants)
		{
			TrySetSelectedPlant(plant, event.mouseButton.x, event.mouseButton.y);
		}
	}

	if (selectedPlant != nullptr && event.key.code == sf::Keyboard::Space)
	{
		selectedPlant->ShootSuper();
	}
}

void PVZScene::TrySetSelectedPlant(Plant* plant, int x, int y)
{
	if (plant->IsInside(x, y) == false)
		return;

	selectedPlant = plant;
}

void PVZScene::OnUpdate()
{
	if (selectedPlant != nullptr)
	{
		sf::Vector2f position = selectedPlant->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}

bool PVZScene::AreZombiesInRow(int rowNumber)
{
	if (rowNumber < 0 || rows.size() < rowNumber + 1)
		return false;

	return rows[rowNumber].size() > 0;
}

void PVZScene::RemovePlant(Plant* plantToRemove)
{
	for (Plant* plant : plants)
	{
		if (plant == plantToRemove)
		{
			plants.push_back(plantToRemove);
			plant->~Plant();
		}
	}
}

void PVZScene::RemoveZombie(Zombie* zombieToRemove)
{
	for (std::vector<Zombie*>& zombieVector : rows)
	{
		zombieVector.erase(std::remove(zombieVector.begin(), zombieVector.end(), zombieToRemove), zombieVector.end());
	}
}
