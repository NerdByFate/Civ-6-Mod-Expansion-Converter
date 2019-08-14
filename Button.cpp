#include "Button.h"

Button::Button() {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile(("gen_button_unpressed.png"), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile(("gen_button_pressed.png"), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(0, 0);

	setScale(1.0f, 1.0f);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(0, 0);
	vArray[1].position = sf::Vector2f(64, 0);
	vArray[2].position = sf::Vector2f(64, 64);
	vArray[3].position = sf::Vector2f(0, 64);

	vArray[0].texCoords = sf::Vector2f(0, 0);
	vArray[1].texCoords = sf::Vector2f(64, 0);
	vArray[2].texCoords = sf::Vector2f(64, 64);
	vArray[3].texCoords = sf::Vector2f(0, 64);

	buttonText.setFont(font);
	buttonText.setString("Next");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight()/2) - (((buttonText.getLocalBounds().height))/2)));
}

Button::Button(float pos[2]) {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile(("gen_button_unpressed.png"), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile(("gen_button_pressed.png"), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(pos[0], pos[1]);

	setScale(1.0f, 1.0f);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(pos[0], pos[1]);
	vArray[1].position = sf::Vector2f(pos[0]+64, pos[1]);
	vArray[2].position = sf::Vector2f(pos[0]+64, pos[1]+64);
	vArray[3].position = sf::Vector2f(pos[0], pos[1]+64);

	vArray[0].texCoords = sf::Vector2f(pos[0], pos[1]);
	vArray[1].texCoords = sf::Vector2f(pos[0]+64, pos[1]);
	vArray[2].texCoords = sf::Vector2f(pos[0]+64, pos[1]+64);
	vArray[3].texCoords = sf::Vector2f(pos[0], pos[1]+64);

	buttonText.setFont(font);
	buttonText.setString("Next");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
}

Button::Button(float pos[2], float scale[2]) {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile(("gen_button_unpressed.png"), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile(("gen_button_pressed.png"), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(pos[0], pos[1]);

	setScale(scale[0], scale[1]);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(pos[0], pos[1]);
	vArray[1].position = sf::Vector2f(pos[0] + 64, pos[1]);
	vArray[2].position = sf::Vector2f(pos[0] + 64, pos[1] + 64);
	vArray[3].position = sf::Vector2f(pos[0], pos[1] + 64);

	vArray[0].texCoords = sf::Vector2f(pos[0], pos[1]);
	vArray[1].texCoords = sf::Vector2f(pos[0] + 64, pos[1]);
	vArray[2].texCoords = sf::Vector2f(pos[0] + 64, pos[1] + 64);
	vArray[3].texCoords = sf::Vector2f(pos[0], pos[1] + 64);

	buttonText.setFont(font);
	buttonText.setString("Next");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
}

Button::Button(float pos[2], float scale[2], int size[2]) {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile(("gen_button_unpressed.png"), sf::IntRect(0, 0, size[0], size[1]))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile(("gen_button_pressed.png"), sf::IntRect(0, 0, size[0], size[1]))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(pos[0], pos[1]);

	setScale(scale[0], scale[1]);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(pos[0], pos[1]);
	vArray[1].position = sf::Vector2f(pos[0] + size[0], pos[1]);
	vArray[2].position = sf::Vector2f(pos[0] + size[0], pos[1] + size[1]);
	vArray[3].position = sf::Vector2f(pos[0], pos[1] + size[1]);

	vArray[0].texCoords = sf::Vector2f(pos[0], pos[1]);
	vArray[1].texCoords = sf::Vector2f(pos[0] + size[0], pos[1]);
	vArray[2].texCoords = sf::Vector2f(pos[0] + size[0], pos[1] + size[1]);
	vArray[3].texCoords = sf::Vector2f(pos[0], pos[1] + size[1]);

	buttonText.setFont(font);
	buttonText.setString("Next");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
}

Button::Button(std::string paths[2]) {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile((paths[0]), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile((paths[1]), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(0, 0);

	setScale(1.0f, 1.0f);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(0, 0);
	vArray[1].position = sf::Vector2f(64, 0);
	vArray[2].position = sf::Vector2f(64, 64);
	vArray[3].position = sf::Vector2f(0, 64);

	vArray[0].texCoords = sf::Vector2f(0, 0);
	vArray[1].texCoords = sf::Vector2f(64, 0);
	vArray[2].texCoords = sf::Vector2f(64, 64);
	vArray[3].texCoords = sf::Vector2f(0, 64);

	buttonText.setFont(font);
	buttonText.setString("Next");
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
}

Button::Button(std::string paths[2], std::string text) {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile((paths[0]), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile((paths[1]), sf::IntRect(0, 0, 64, 64))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(0, 0);

	setScale(1.0f, 1.0f);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(0, 0);
	vArray[1].position = sf::Vector2f(64, 0);
	vArray[2].position = sf::Vector2f(64, 64);
	vArray[3].position = sf::Vector2f(0, 64);

	vArray[0].texCoords = sf::Vector2f(0, 0);
	vArray[1].texCoords = sf::Vector2f(64, 0);
	vArray[2].texCoords = sf::Vector2f(64, 64);
	vArray[3].texCoords = sf::Vector2f(0, 64);

	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
}

Button::Button(std::string paths[2], std::string text, float pos[2], float scale[2], int size[2]) {
	isPressed = false;

	buttonUnpressed = new sf::Texture();
	buttonPressed = new sf::Texture();

	if (!buttonUnpressed->loadFromFile((paths[0]), sf::IntRect(0, 0, size[0], size[1]))) {
		std::cout << "Could not load texture buttonUnpressed. If you are reading this, please exit the application.\n";
	}
	if (!buttonPressed->loadFromFile((paths[1]), sf::IntRect(0, 0, size[0], size[1]))) {
		std::cout << "Could not load texture buttonPressed. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {

	}

	setPosition(pos[0], pos[1]);

	setScale(scale[0], scale[1]);

	vArray.setPrimitiveType(sf::Quads);
	vArray.resize(4);
	vArray[0].position = sf::Vector2f(pos[0], pos[1]);
	vArray[1].position = sf::Vector2f(pos[0] + size[0], pos[1]);
	vArray[2].position = sf::Vector2f(pos[0] + size[0], pos[1] + size[1]);
	vArray[3].position = sf::Vector2f(pos[0], pos[1] + size[1]);

	vArray[0].texCoords = sf::Vector2f(pos[0], pos[1]);
	vArray[1].texCoords = sf::Vector2f(pos[0] + size[0], pos[1]);
	vArray[2].texCoords = sf::Vector2f(pos[0] + size[0], pos[1] + size[1]);
	vArray[3].texCoords = sf::Vector2f(pos[0], pos[1] + size[1]);

	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(30);
	buttonText.setFillColor(sf::Color::White);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(2.0f);
	buttonText.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();

	if (GetManualPressed()) {
		states.texture = buttonPressed;
	}
	else {
		states.texture = buttonUnpressed;
	}

	target.draw(vArray, states);
	target.draw(buttonText);
}

float Button::GetHeight() const {
	return vArray.getBounds().height * getScale().y;
}

void Button::SetSize(float x, float y) {
	vArray[0].position = sf::Vector2f(getPosition().x, getPosition().y);
	vArray[1].position = sf::Vector2f(getPosition().x + x, getPosition().y);
	vArray[2].position = sf::Vector2f(getPosition().x + x, getPosition().y + y);
	vArray[3].position = sf::Vector2f(getPosition().x, getPosition().y + y);

	vArray[0].texCoords = sf::Vector2f(getPosition().x, getPosition().y);
	vArray[1].texCoords = sf::Vector2f(getPosition().x + x, getPosition().y);
	vArray[2].texCoords = sf::Vector2f(getPosition().x + x, getPosition().y + y);
	vArray[3].texCoords = sf::Vector2f(getPosition().x, getPosition().y + y);
}

float Button::GetWidth() const {
	return vArray.getBounds().width * getScale().x;
}

bool Button::isButtonPressed(sf::RenderWindow& window) const {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= getPosition().x && sf::Mouse::getPosition(window).x <= getPosition().x + GetWidth() && sf::Mouse::getPosition(window).y >= getPosition().y && sf::Mouse::getPosition(window).y <= getPosition().y + GetHeight()) {
		return true;
	}
	else {
		return false;
	}
}

void Button::UpdatePositions() {
	sf::Text text;
	text = GetButtonText();
	text.setPosition((getPosition().x) + ((GetWidth() / 2) - (((buttonText.getLocalBounds().width)) / 2)), (getPosition().y - 7) + ((GetHeight() / 2) - (((buttonText.getLocalBounds().height)) / 2)));
	SetButtonText(text);
}

bool Button::GetManualPressed() const {
	return isPressed;
}

void Button::SetManualPressed(bool pressedUnpressed) {
	isPressed = pressedUnpressed;
}

sf::Text Button::GetButtonText() const {
	return buttonText;
}

void Button::SetButtonText(sf::Text text) {
	buttonText = text;
}

sf::Texture* Button::GetButtonUnpressedTexture() const {
	return buttonUnpressed;
}

void Button::SetButtonUnpressedTexture(sf::Texture* button0) {
	buttonUnpressed = button0;
}

sf::Texture* Button::GetButtonPressedTexture() const {
	return buttonPressed;
}

void Button::SetButtonPressedTexture(sf::Texture* button1) {
	buttonPressed = button1;
}

sf::VertexArray Button::GetVertexArray() const {
	return vArray;
}

void Button::SetVertexArray(sf::VertexArray v) {
	vArray = v;
}
