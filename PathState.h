#pragma once
#ifndef PATHSTATE_H
#define PATHSTATE_H
#include "State.h"
#include "MainState.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class PathState : State {
public:
	PathState(); //Constructor
	int Render(sf::RenderWindow& window);
	void HandleEvents(sf::RenderWindow& window, sf::String& input);

	sf::Clock GetNextTimer() const;
	void SetNextTimer(sf::Clock nextTimer);
	sf::RectangleShape GetBackground() const;
	void SetBackground(sf::RectangleShape background);
	sf::RectangleShape GetPathBox() const;
	void SetPathBox(sf::RectangleShape pathBox);
	sf::RectangleShape GetGreyBox() const;
	void SetGreyBox(sf::RectangleShape greyBox);
	sf::RectangleShape GetPathGreyBox() const;
	void SetPathGreyBox(sf::RectangleShape pathGreyBox);
	Button GetNextButton() const;
	void SetNextButton(Button next);
	sf::Font GetFont() const;
	void SetFont(sf::Font font);
	sf::Text GetUserInputText() const;
	void SetUserInputText(sf::Text userInput);
	sf::Text GetPromptText() const;
	void SetPromptText(sf::Text prompt);
	sf::Text GetPathHeaderText() const;
	void SetPathHeaderText(sf::Text pathHeader);
	sf::String GetInput();
	void SetInput(sf::String input);
	sf::Event GetEvent() const;
	void SetEvent(sf::Event event);
private:
	bool nextPressed;
	sf::Clock nextTimer;
	sf::RectangleShape pathBox;
	sf::RectangleShape greyBox;
	sf::RectangleShape pathGreyBox;
	sf::RectangleShape background;
	Button next;
	sf::Font trebuc;
	sf::Text userInput;
	sf::Text prompt;
	sf::Text pathHeader;
	sf::String input;
	sf::Event event;
};
#endif //PATHSTATE_H
