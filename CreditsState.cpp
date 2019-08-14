#include "CreditsState.h"

CreditsState::CreditsState() {
	SetPositionSet(false);

	if (!icon.loadFromFile("icon.png", sf::IntRect(0, 0, 104, 82))) {
		std::cout << "Could not load icon. If you are reading this, please exit the application.\n";
	}

	icon.setSmooth(true);

	if (!trebuc.loadFromFile("trebuc.ttf")) {
		std::cout << "Could not load. If you are reading this, please exit the application.\n";
	}

	background.setSize(sf::Vector2f(1276, 716));
	background.setPosition(2.0f, 2.0f);
	background.setFillColor(sf::Color(0, 34, 255, 255));
	background.setOutlineColor(sf::Color(0, 255, 255, 255));
	background.setOutlineThickness(2.0f);

	iconSprite.setScale(1.3f, 1.3f);
	iconSprite.setPosition((background.getSize().x/4)*3, (background.getSize().y/4));
	iconSprite.setTexture(icon);

	message.setFont(trebuc);
	message.setString("Thank you for using the Civilization VI Mod Expansion Converter.\nEnjoy your freshly updated mod(s)!");
	message.setCharacterSize(20);
	message.setFillColor(sf::Color(0, 0, 0, 255));
	message.setOutlineColor(sf::Color(255, 255, 255, 255));
	message.setOutlineThickness(1.0f);

	advert.setFont(trebuc);
	advert.setString("This application was created by NerdByFate, and you can view its creation on YouTube.\nFeel free to search for that username on GitHub or CivFanatics to view some of my other works.");
	advert.setCharacterSize(20);
	advert.setFillColor(sf::Color(0, 0, 0, 255));
	advert.setOutlineColor(sf::Color(255, 255, 255, 255));
	advert.setOutlineThickness(1.0f);
}

int CreditsState::Render(sf::RenderWindow& window) {
	HandleEvents(window);

	if (!GetPositionSet()) {
		message.setPosition(0, background.getPosition().y + (background.getSize().y / 8));
		advert.setPosition(0, background.getPosition().y + ((background.getSize().y / 4) * 3));
		SetPositionSet(true);
	}

	window.clear();
	window.draw(background);
	window.draw(iconSprite);
	window.draw(message);
	window.draw(advert);
	window.display();

	return 3;
}

void CreditsState::HandleEvents(sf::RenderWindow& window) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			break;
		}
	}
}
