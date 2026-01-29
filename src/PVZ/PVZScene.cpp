#include "PVZScene.h"

#include "Plant.h"
#include "Zombie.h"
#include "Projectile.h"

#include "Debug.h"
#include <iostream>
#include <vector>

void SampleScene::OnInitialize()
{
	rowsAmount = 3;

	for (int i = 0; i < rowsAmount; i++)
	{
		Plant* temp = CreateEntity<Plant>(50, sf::Color::Green);

		temp->SetPosition(temp->GetRadius() + 10, i * (GetWindowHeight() / rowsAmount) + (GetWindowHeight() / (rowsAmount * 2)));

		plants.push_back(std::vector<Plant*>());

		plants[i].push_back(temp);
	}

	selectedPlant = nullptr;
}

void SampleScene::OnEvent(const sf::Event& event)
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

				break;
			}
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		for (std::vector<Plant*> plantVector : plants)
		{
			for (Plant* plant : plantVector)
			{
				TrySetSelectedPlant(plant, event.mouseButton.x, event.mouseButton.y);
			}
		}
	}

	if (selectedPlant != nullptr && event.key.code == sf::Keyboard::Space)
	{
		selectedPlant->ShootSuper();
	}
}

void SampleScene::TrySetSelectedPlant(Plant* plant, int x, int y)
{
	if (plant->IsInside(x, y) == false)
		return;

	selectedPlant = plant;
}

void SampleScene::OnUpdate()
{
	if (selectedPlant != nullptr)
	{
		sf::Vector2f position = selectedPlant->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}
