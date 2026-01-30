#include "pch.h"
#include "main.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "PVZScene.h"

#include <cstdlib>
#include <crtdbg.h>

int main()
{
	GameManager* pInstance = GameManager::Get();

	std::cout << pInstance->GetFont().getInfo().family << std::endl;

	//sf::Font font;
	//if (!font.openFromFile("arial.ttf"))
	//{
		// error...
	//}

	pInstance->CreateWindow(1280, 720, "Scène test", 60, sf::Color::Black);

	pInstance->LaunchScene<PVZScene>();

	return 0;
}
