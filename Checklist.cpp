#include "Checklist.h"

Checklist::Checklist() {
	canScroll = false;

	background.setSize(sf::Vector2f(358, 638));
	background.setPosition(0, 0);
	background.setFillColor(sf::Color(0, 10, 255, 255));
	background.setOutlineColor(sf::Color(0, 255, 255, 255));
	background.setOutlineThickness(2.0f);

	scrollAxisArray.setPrimitiveType(sf::Quads);
	scrollAxisArray.resize(4);
	scrollAxisArray[0].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	scrollAxisArray[0].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	if (!upArrowTexture0.loadFromFile("up_arrow_unpressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture upArrowTexture0. If you are reading this, please exit the application.\n";
	}
	if (!upArrowTexture1.loadFromFile("up_arrow_pressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture upArrowTexture1. If you are reading this, please exit the application.\n";
	}
	if (!downArrowTexture0.loadFromFile("down_arrow_unpressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture downArrowTexture0. If you are reading this, please exit the application.\n";
	}
	if (!downArrowTexture1.loadFromFile("down_arrow_pressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture downArrowTexture1. If you are reading this, please exit the application.\n";
	}

	upArrow.SetSize(16, 16);
	upArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y);
	upArrow.SetButtonText(sf::Text());
	upArrow.SetButtonUnpressedTexture(&upArrowTexture0);
	upArrow.SetButtonPressedTexture(&upArrowTexture1);

	downArrow.SetSize(16, 16);
	downArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + (background.getSize().y - 16));
	downArrow.SetButtonText(sf::Text());
	downArrow.SetButtonUnpressedTexture(&downArrowTexture0);
	downArrow.SetButtonPressedTexture(&downArrowTexture1);

	scrollBox.setSize(sf::Vector2f(16, 606));
	scrollBox.setPosition(background.getPosition().x + (background.getSize().x - 15), background.getPosition().y + 16);
	scrollBox.setFillColor(sf::Color(0, 245, 255, 255));
	scrollBox.setOutlineColor(sf::Color(0, 10, 255, 255));
	scrollBox.setOutlineThickness(2.0f);

	if (!checkBox0.loadFromFile("check_box_unpressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture checkBox0. If you are reading this, please exit the application.\n";
	}
	if (!checkBox1.loadFromFile("check_box_pressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture checkBox1. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {
		std::cout << "Could not load texture trebuc. If you are reading this, please exit the application.\n";
	}

	cView.reset(sf::FloatRect(1280, 0, background.getSize().x, background.getSize().y));
	cView.setViewport(sf::FloatRect(0, 0, background.getSize().x/1280, background.getSize().y/720));
}

Checklist::Checklist(float pos[2]) {
	canScroll = false;

	background.setSize(sf::Vector2f(358, 638));
	background.setPosition(pos[0], pos[1]);
	background.setFillColor(sf::Color(0, 10, 255, 255));
	background.setOutlineColor(sf::Color(0, 255, 255, 255));
	background.setOutlineThickness(2.0f);

	scrollAxisArray.setPrimitiveType(sf::Quads);
	scrollAxisArray.resize(4);
	scrollAxisArray[0].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	scrollAxisArray[0].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	if (!upArrowTexture0.loadFromFile("up_arrow_unpressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture upArrowTexture0. If you are reading this, please exit the application.\n";
	}
	if (!upArrowTexture1.loadFromFile("up_arrow_pressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture upArrowTexture1. If you are reading this, please exit the application.\n";
	}
	if (!downArrowTexture0.loadFromFile("down_arrow_unpressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture downArrowTexture0. If you are reading this, please exit the application.\n";
	}
	if (!downArrowTexture1.loadFromFile("down_arrow_pressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture downArrowTexture1. If you are reading this, please exit the application.\n";
	}

	upArrow.SetSize(16, 16);
	upArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y);
	upArrow.SetButtonText(sf::Text());
	upArrow.SetButtonUnpressedTexture(&upArrowTexture0);
	upArrow.SetButtonPressedTexture(&upArrowTexture1);

	downArrow.SetSize(16, 16);
	downArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + (background.getSize().y - 16));
	downArrow.SetButtonText(sf::Text());
	downArrow.SetButtonUnpressedTexture(&downArrowTexture0);
	downArrow.SetButtonPressedTexture(&downArrowTexture1);

	scrollBox.setSize(sf::Vector2f(16, 606));
	scrollBox.setPosition(background.getPosition().x + (background.getSize().x - 15), background.getPosition().y + 16);
	scrollBox.setFillColor(sf::Color(0, 245, 255, 255));
	scrollBox.setOutlineColor(sf::Color(0, 10, 255, 255));
	scrollBox.setOutlineThickness(2.0f);

	if (!checkBox0.loadFromFile("check_box_unpressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture checkBox0. If you are reading this, please exit the application.\n";
	}
	if (!checkBox1.loadFromFile("check_box_pressed.png", sf::IntRect(0, 0, 16, 16))) {
		std::cout << "Could not load texture checkBox1. If you are reading this, please exit the application.\n";
	}

	if (!font.loadFromFile("trebuc.ttf")) {
		std::cout << "Could not load texture trebuc. If you are reading this, please exit the application.\n";
	}

	cView.reset(sf::FloatRect(1280, 0, background.getSize().x, background.getSize().y));
	cView.setViewport(sf::FloatRect(pos[0] / 1280, pos[1] / 720, background.getSize().x / 1280, background.getSize().y / 720));
}

void Checklist::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	//TODO: Set the transforms of all of the other drawables to getTransform

	target.setView(target.getDefaultView());
	target.draw(background);
	target.draw(upArrow);
	target.draw(downArrow);
	target.draw(scrollBox);

	target.setView(cView);
	for (int i = 0; i < items.size(); i++) {
		target.draw(itemsText[i]);
	}

	for (int c = 0; c < checkBoxes.size(); c++) {
		target.draw(checkBoxes[c]);
	}
}

void Checklist::InsertItems(std::vector<std::experimental::filesystem::path> itemsS) {
	std::vector<std::experimental::filesystem::path> tempV;

	for (int i = 0; i < itemsS.size(); i++) {
		tempV.push_back(itemsS[i]);
	}

	for (int y = 0; y < tempV.size(); y++) {
		Checkbox temp;
		temp.SetSize(16, 16);
		temp.SetButtonUnpressedTexture(&checkBox0);
		temp.SetButtonPressedTexture(&checkBox1);
		temp.SetButtonText(sf::Text());

		temp.setPosition(1281, 2 + y * 16);
		checkBoxes.push_back(temp);
	}

	SetItems(tempV);
	CreateText();
}

void Checklist::CreateText() {
	std::vector<sf::Text> tempV;

	for (int i = 0; i < GetItems().size(); i++) {
		sf::Text temp(GetItems()[i].filename().u8string(), font, 16);
		temp.setFillColor(sf::Color(0, 0, 0, 255));
		temp.setOutlineColor(sf::Color(255, 255, 255, 255));
		temp.setOutlineThickness(1.0f);

		tempV.push_back(temp);
	}

	for (int y = 0; y < tempV.size(); y++) {
		tempV[y].setPosition(1300, y * 16);
	}

	if ((tempV[tempV.size()-1].getPosition().y + tempV[tempV.size() - 1].getLocalBounds().height) > (background.getPosition().y + background.getLocalBounds().height)) {
		scrollBox.setSize(sf::Vector2f(scrollBox.getSize().x, (scrollBox.getSize().y * ((background.getPosition().y + background.getLocalBounds().height) / (tempV[tempV.size() - 1].getPosition().y + tempV[tempV.size() - 1].getLocalBounds().height)) - scrollAxisArray[0].position.y - downArrow.GetHeight())));
		canScroll = true;
	}

	SetItemsText(tempV);
}

void Checklist::HandleEvents(sf::RenderWindow& window) {
	for (int i = 0; i < checkBoxes.size(); i++) {
		if (checkBoxes[i].isButtonPressed(window) && checkBoxes[i].GetManualPressed() == false && checkTimer.getElapsedTime().asSeconds() >= 0.15f) {
			checkBoxes[i].SetManualPressed(true);
			checkTimer.restart();
		}
		else if (checkBoxes[i].isButtonPressed(window) && checkBoxes[i].GetManualPressed() == true && checkTimer.getElapsedTime().asSeconds() >= 0.15f) {
			checkBoxes[i].SetManualPressed(false);
			checkTimer.restart();
		}
	}
}

void Checklist::Scroll(float toLocation) {
	if (canScroll) {
		if (toLocation + scrollBox.getSize().y > scrollAxisArray[2].position.y) {
			toLocation = scrollAxisArray[2].position.y - scrollBox.getLocalBounds().height;
		}
		else if (toLocation < scrollAxisArray[0].position.y) {
			toLocation = scrollAxisArray[0].position.y;
		}

		scrollBox.setPosition(scrollBox.getPosition().x, toLocation);
		cView.reset(sf::FloatRect(1280, (toLocation - scrollAxisArray[0].position.y) * (((GetItemsText()[GetItemsText().size() - 1].getPosition().y + GetItemsText()[GetItemsText().size() - 1].getLocalBounds().height)) / (background.getPosition().y + background.getLocalBounds().height)), background.getSize().x, background.getSize().y));
	}
}

void Checklist::setPosition(float x, float y) {
	background.setPosition(x,y);

	scrollAxisArray[0].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	scrollAxisArray[0].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	upArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y);

	downArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + (background.getSize().y - 16));

	scrollBox.setPosition(background.getPosition().x + (background.getSize().x - 15), background.getPosition().y + 16);

	cView.setViewport(sf::FloatRect(x / 1280, y / 720, background.getSize().x / 1280, background.getSize().y / 720));
}

void Checklist::setPosition(const sf::Vector2f pos) {
	background.setPosition(pos.x, pos.y);

	scrollAxisArray[0].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].position = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].position = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	scrollAxisArray[0].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + 16);
	scrollAxisArray[1].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + 16);
	scrollAxisArray[2].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x), background.getPosition().y + background.getSize().y - 16);
	scrollAxisArray[3].texCoords = sf::Vector2f(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + background.getSize().y - 16);

	upArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y);

	downArrow.setPosition(background.getPosition().x + (background.getSize().x - 16), background.getPosition().y + (background.getSize().y - 16));

	scrollBox.setPosition(background.getPosition().x + (background.getSize().x - 15), background.getPosition().y + 16);

	cView.setViewport(sf::FloatRect(pos.x / 1280, pos.y / 720, background.getSize().x / 1280, background.getSize().y / 720));
}

sf::Vector2f Checklist::getPosition() const {
	return GetBackground().getPosition();
}

sf::RectangleShape Checklist::GetBackground() const {
	return background;
}

void Checklist::SetBackground(sf::RectangleShape bg) {
	background = bg;
}

sf::VertexArray Checklist::GetScrollAxisArray() const {
	return scrollAxisArray;
}

void Checklist::SetScrollAxisArray(sf::VertexArray scrollAxisA) {
	scrollAxisArray = scrollAxisA;
}

sf::Texture Checklist::GetUpArrowUnpressedTexture() const {
	return upArrowTexture0;
}

void Checklist::SetUpArrowUnpressedTexture(sf::Texture upA0) {
	upArrowTexture0 = upA0;
}

sf::Texture Checklist::GetUpArrowPressedTexture() const {
	return upArrowTexture1;
}

void Checklist::SetUpArrowPressedTexture(sf::Texture upA1) {
	upArrowTexture1 = upA1;
}

sf::Texture Checklist::GetDownArrowUnpressedTexture() const {
	return downArrowTexture0;
}

void Checklist::SetDownArrowUnpressedTexture(sf::Texture downA0) {
	downArrowTexture0 = downA0;
}

sf::Texture Checklist::GetDownArrowPressedTexture() const {
	return downArrowTexture1;
}

void Checklist::SetDownArrowPressedTexture(sf::Texture downA1) {
	downArrowTexture1 = downA1;
}

sf::RectangleShape Checklist::GetScrollBox() const {
	return scrollBox;
}

void Checklist::SetScrollBox(sf::RectangleShape scrollB) {
	scrollBox = scrollB;
}

std::vector<std::experimental::filesystem::path> Checklist::GetItems() const {
	return items;
}

void Checklist::SetItems(std::vector<std::experimental::filesystem::path> i) {
	items = i;
}

std::vector<sf::Text> Checklist::GetItemsText() const {
	return itemsText;
}

void Checklist::SetItemsText(std::vector<sf::Text> iText) {
	itemsText = iText;
}

sf::Texture Checklist::GetCheckBoxUnpressedTexture() const {
	return checkBox0;
}

void Checklist::SetCheckBoxUnpressedTexure(sf::Texture checkB0) {
	checkBox0 = checkB0;
}

sf::Texture Checklist::GetCheckBoxPressedTexture() const {
	return checkBox1;
}

void Checklist::SetCheckBoxPressedTexure(sf::Texture checkB1) {
	checkBox1 = checkB1;
}

std::vector<Checkbox> Checklist::GetCheckboxes() const {
	return checkBoxes;
}

void Checklist::SetCheckboxes(std::vector<Checkbox> checkBox) {
	checkBoxes = checkBox;
}

sf::View Checklist::GetChecklistView() const {
	return cView;
}

void Checklist::SetChecklistView(sf::View cV) {
	cView = cV;
}

sf::Font Checklist::GetFont() const {
	return font;
}

void Checklist::SetFont(sf::Font f) {
	font = f;
}

sf::Clock Checklist::GetCheckTimer() const {
	return checkTimer;
}

void Checklist::SetCheckTimer(sf::Clock checkT) {
	checkTimer = checkT;
}

bool Checklist::GetCanScroll() const {
	return canScroll;
}

void Checklist::SetCanScroll(bool canS) {
	canScroll = canS;
}
