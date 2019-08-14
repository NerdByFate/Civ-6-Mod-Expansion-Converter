#pragma once
#ifndef CHECKLIST_H
#define CHECKLIST_H
#include <SFML/Graphics.hpp>
#include <experimental/filesystem>
#include "Checkbox.h"
#include "Button.h"

class Checklist : public sf::Drawable, public sf::Transformable {
public:
	//Constructors
	Checklist();
	Checklist(float pos[2]);

	//Public Functions
	void HandleEvents(sf::RenderWindow& window);
	void InsertItems(std::vector<std::experimental::filesystem::path> items);
	void CreateText();
	void Scroll(float toLocation);

	//SFML Overrides
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();

	//Getters & Setters
	sf::RectangleShape GetBackground() const;
	void SetBackground(sf::RectangleShape background);
	sf::VertexArray GetScrollAxisArray() const;
	void SetScrollAxisArray(sf::VertexArray scrollAxisArray);
	sf::Texture GetUpArrowUnpressedTexture() const;
	void SetUpArrowUnpressedTexture(sf::Texture upArrow0);
	sf::Texture GetUpArrowPressedTexture() const;
	void SetUpArrowPressedTexture(sf::Texture upArrow1);
	sf::Texture GetDownArrowUnpressedTexture() const;
	void SetDownArrowUnpressedTexture(sf::Texture downArrow0);
	sf::Texture GetDownArrowPressedTexture() const;
	void SetDownArrowPressedTexture(sf::Texture downArrow1);
	sf::RectangleShape GetScrollBox() const;
	void SetScrollBox(sf::RectangleShape scrollBox);
	std::vector<std::experimental::filesystem::path> GetItems() const;
	void SetItems(std::vector<std::experimental::filesystem::path> items);
	std::vector<sf::Text> GetItemsText() const;
	void SetItemsText(std::vector<sf::Text> itemsText);
	sf::Texture GetCheckBoxUnpressedTexture() const;
	void SetCheckBoxUnpressedTexure(sf::Texture checkBox0);
	sf::Texture GetCheckBoxPressedTexture() const;
	void SetCheckBoxPressedTexure(sf::Texture checkBox1);
	std::vector<Checkbox> GetCheckboxes() const;
	void SetCheckboxes(std::vector<Checkbox> checkBoxes);
	sf::View GetChecklistView() const;
	void SetChecklistView(sf::View cView);
	sf::Font GetFont() const;
	void SetFont(sf::Font font);
	sf::Clock GetCheckTimer() const;
	void SetCheckTimer(sf::Clock checkTimer);
	bool GetCanScroll() const;
	void SetCanScroll(bool canScroll);

	//Public Members
	Button upArrow;
	Button downArrow;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape background;
	sf::VertexArray scrollAxisArray;
	sf::Texture upArrowTexture0;
	sf::Texture upArrowTexture1;
	sf::Texture downArrowTexture0;
	sf::Texture downArrowTexture1;
	sf::RectangleShape scrollBox;
	std::vector<std::experimental::filesystem::path> items;
	std::vector<sf::Text> itemsText;
	sf::Texture checkBox0;
	sf::Texture checkBox1;
	std::vector<Checkbox> checkBoxes;
	sf::View cView;
	sf::Font font;
	sf::Clock checkTimer;
	bool canScroll;
	int eventIndex;
};
#endif //CHECKLIST_H
