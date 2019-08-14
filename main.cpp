#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainState.h"
#include "PathState.h"
#include "CreditsState.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Civilization VI Mod Converter", sf::Style::Titlebar | sf::Style::Close);

	sf::Image icon;
	if (!icon.loadFromFile("icon.png")) {
		std::cout << "Could not load icon. If you are reading this, please exit the application.\n";
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	PathState pathState; //state id 1
	MainState mainState; //state id 2
	CreditsState creditsState; //state id 3
	int gameState = 1;

	bool pathSet = false;

	while (window.isOpen()) {
		if (gameState == 1) {
			gameState = pathState.Render(window);
		}
		else if (gameState == 2) {
			if (!pathSet) {
				if (((std::string)pathState.GetUserInputText().getString()).back() == '\\') {
					mainState.SetPath(pathState.GetUserInputText().getString() + "steamapps\\workshop\\content\\289070\\");
				}
				else if (((std::string)pathState.GetUserInputText().getString()).back() == '/') {
					mainState.SetPath(pathState.GetUserInputText().getString() + "steamapps/workshop/content/289070/");
				}
				else {
					mainState.SetPath(pathState.GetUserInputText().getString() + "\\steamapps\\workshop\\content\\289070\\");
				}
				pathSet = true;
			}
			gameState = mainState.Render(window);
		}
		else if (gameState == 3) {
			gameState = creditsState.Render(window);
		}
		else {
			window.close();
		}
	}
	return 0;
}
