#pragma once
#ifndef MAINSTATE_H
#define MAINSTATE_H
#include "State.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <experimental/filesystem>
#include "Button.h"
#include "XMLStream.h"
#include "Checklist.h"

class MainState : State {
public:
	MainState(); //Constructor
	int Render(sf::RenderWindow& window);
	void HandleEvents(sf::RenderWindow& window);

	sf::String GetPath() const;
	void SetPath(sf::String path);
	sf::RectangleShape GetBackground() const;
	void SetBackground(sf::RectangleShape background);
	sf::Texture GetRiseAndFallUnpressed() const;
	void SetRiseAndFallUnpressed(sf::Texture rf0);
	sf::Texture GetRiseAndFallPressed() const;
	void SetRiseAndFallPressed(sf::Texture rf1);
	sf::Texture GetGatheringStormUnpressed() const;
	void SetGatheringStormUnpressed(sf::Texture gs0);
	sf::Texture GetGatheringStormPressed() const;
	void SetGatheringStormPressed(sf::Texture gs1);
	sf::Texture GetConvertUnpressed() const;
	void SetConvertUnpressed(sf::Texture convert0);
	sf::Texture GetConvertPressed() const;
	void SetConvertPressed(sf::Texture convert1);
	sf::Texture GetGenericUnpressed() const;
	void SetGenericUnpressed(sf::Texture gen0);
	sf::Texture GetGenericPressed() const;
	void SetGenericPressed(sf::Texture gen1);
	sf::Font GetFont() const;
	void SetFont(sf::Font font);
	sf::Text GetExpansionHeaderText() const;
	void SetExpansionHeaderText(sf::Text expansionHeader);
	sf::Text GetModNamesText() const;
	void SetModNamesText(sf::Text modNames);
	sf::Text GetDoneText() const;
	void SetDoneText(sf::Text done);
	Checklist GetChecklist() const;
	void SetChecklist(Checklist cList);
	Button GetRiseAndFallButton() const;
	void SetRiseAndFallButton(Button riseAndFall);
	Button GetGatheringStormButton() const;
	void SetGatheringStormButton(Button gatheringStorm);
	Button GetConvertButton() const;
	void SetConvertButton(Button convert);
	sf::VertexArray GetButtonGrid() const;
	void SetButtonGrid(sf::VertexArray buttonGrid);
	sf::Texture* GetButtonGridTexture() const;
	void SetButtonGridTexture(sf::Texture* buttonGridTexture);
private:
	bool filesHandled;
	sf::String path;
	Checklist cList;
	sf::RectangleShape background;
	sf::Texture rf0;
	sf::Texture rf1;
	sf::Texture gs0;
	sf::Texture gs1;
	sf::Texture convert0;
	sf::Texture convert1;
	sf::Texture gen0;
	sf::Texture gen1;
	Button riseAndFall;
	Button gatheringStorm;
	Button convert;
	sf::Font trebuc;
	sf::Text expansionHeader;
	sf::Text modNames;
	sf::Text done;
	sf::VertexArray buttonGrid;
	sf::Texture* buttonGridTexture;
	std::vector<std::string> items;
	XMLStream xStream;
	sf::Event event;
	bool convertPressed;
	sf::Clock checkTimer;
	bool scrolling;
	float delta;
};
#endif //MAINSTATE_H
