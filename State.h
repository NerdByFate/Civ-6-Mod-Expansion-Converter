#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class State {
public:
	State();
	int Render(sf::RenderWindow& window);
	void HandleEvents(sf::RenderWindow& window);
	
	sf::Event GetEvent() const;
	void SetEvent(sf::Event e);
	bool GetPositionSet() const;
	void SetPositionSet(bool posSet);
private:
	sf::Event event;

	bool positionSet;
};
#endif //STATE_H

