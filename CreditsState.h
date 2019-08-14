#pragma once
#ifndef CREDITSSTATE_H
#define CREDITSSTATE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.h"

class CreditsState : State {
public:
	CreditsState();
	int Render(sf::RenderWindow& window);
	void HandleEvents(sf::RenderWindow& window);
private:
	sf::RectangleShape background;
	sf::Font trebuc;
	sf::Text message;
	sf::Text advert;
	sf::Texture icon;
	sf::Sprite iconSprite;
	sf::Event event;
};
#endif //CREDITSSTATE_H
