#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::Drawable, public sf::Transformable {
public:
	Button();
	Button(float pos[2]);
	Button(float scale[2], float pos[2]);
	Button(float scale[2], float pos[2], int size[2]);
	Button(std::string paths[2]);
	Button(std::string paths[2], std::string text);
	Button(std::string paths[2], std::string text, float scale[2], float pos[2], int size[2]);
	bool isButtonPressed(sf::RenderWindow& window) const;
	void UpdatePositions();

	float GetWidth() const;
	float GetHeight() const;
	void SetSize(float x, float y);
	bool GetManualPressed() const; //returns set value from SetTexture()
	void SetManualPressed(bool pressedUnpressed); //Set to false if the button is not pressed, set to true if it is pressed
	sf::Text GetButtonText() const;
	void SetButtonText(sf::Text text);
	sf::Texture* GetButtonUnpressedTexture() const;
	void SetButtonUnpressedTexture(sf::Texture* button0);
	sf::Texture* GetButtonPressedTexture() const;
	void SetButtonPressedTexture(sf::Texture* button1);
	sf::VertexArray GetVertexArray() const;
	void SetVertexArray(sf::VertexArray v);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray vArray;
	sf::Texture* buttonUnpressed;
	sf::Texture* buttonPressed;
	sf::Text buttonText;
	sf::Font font;
	bool isPressed;
};
#endif //BUTTON_H
