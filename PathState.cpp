#include "PathState.h"

PathState::PathState() {
	nextPressed = false;
	SetPositionSet(false);

	if (!trebuc.loadFromFile("trebuc.ttf")) {
		std::cout << "Could not load. If you are reading this, please exit the application.\n";
	}

	background.setSize(sf::Vector2f(1276, 716));
	background.setPosition(2.0f, 2.0f);
	background.setFillColor(sf::Color(0, 34, 255, 255));
	background.setOutlineColor(sf::Color(0, 255, 255, 255));
	background.setOutlineThickness(2.0f);
	
	pathBox.setSize(sf::Vector2f(640, 360));
	greyBox.setSize(sf::Vector2f(1280, 720));
	pathGreyBox.setSize(sf::Vector2f(550, 25));

	pathBox.setFillColor(sf::Color(0, 34, 255, 255));
	greyBox.setFillColor(sf::Color(0, 0, 0, 100));
	pathGreyBox.setFillColor(sf::Color(0, 0, 0, 100));

	pathBox.setOutlineColor(sf::Color(0, 255, 255, 255));
	pathBox.setOutlineThickness(2.0f);
	
	prompt.setFont(trebuc);
	prompt.setString("Enter the path of your Steam Installation:");
	prompt.setCharacterSize(20);
	prompt.setFillColor(sf::Color(0, 0, 0, 255));
	prompt.setOutlineColor(sf::Color(255, 255, 255, 255));
	prompt.setOutlineThickness(1.0f);

	userInput.setFont(trebuc);
	userInput.setString("");
	userInput.setCharacterSize(20);
	userInput.setFillColor(sf::Color(0, 0, 0, 255));
	userInput.setOutlineColor(sf::Color(255, 255, 255, 255));
	userInput.setOutlineThickness(1.0f);

	next.setScale(2.0f, 1.0f);

	/*Button temp(2.0f, 1.0f);
	next = temp;*/ // Uncomment on video
}

int PathState::Render(sf::RenderWindow& window) {
	HandleEvents(window, input);

	userInput.setString(GetInput());

	if (!GetPositionSet()) {
		pathBox.setPosition(((window.getSize().x) / 2) - ((GetPathBox().getSize().x) / 2), ((window.getSize().y) / 2) - ((GetPathBox().getSize().y) / 2));
		prompt.setPosition(GetPathBox().getPosition());
		pathGreyBox.setPosition(GetPathBox().getPosition().x, (GetPathBox().getPosition().y) + ((GetPathBox().getSize().y) / 2));
		userInput.setPosition(GetPathBox().getPosition().x, ((GetPathBox().getPosition().y) + ((GetPathBox().getSize().y) / 2)));
		next.setPosition(((GetPathBox().getPosition().x) + (GetPathBox().getSize().x)) - GetNextButton().GetWidth(), ((GetPathBox().getPosition().y) + (GetPathBox().getSize().y)) - GetNextButton().GetHeight()); // Fix once Transformable is inherited
		next.UpdatePositions();
		SetPositionSet(true);
	}

	window.clear();
	window.draw(GetBackground());
	window.draw(GetGreyBox());
	window.draw(GetPathBox());
	window.draw(GetPromptText());
	window.draw(GetPathGreyBox());
	window.draw(GetUserInputText());
	window.draw(next);
	window.display();

	if (nextPressed) {
		return 2;
	}

	return 1;
}

void PathState::HandleEvents(sf::RenderWindow& window, sf::String& textEntered) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::TextEntered:
			if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 13) { //ASCII && != Backspace
				textEntered += static_cast<char>(event.text.unicode);
			}
			else if (event.text.unicode == 8 && textEntered.getSize() >= 1) {
				textEntered.erase(textEntered.getSize() - 1, 1);
			}
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Enter) {
				nextPressed = true;
			}
			break;
		}
	}
	if (next.isButtonPressed(window)) {
		next.SetManualPressed(true);
		if (GetNextTimer().getElapsedTime().asSeconds() >= 0.025f) {
			next.SetManualPressed(false);
			nextPressed = true;
		}
	}
	else {
		nextTimer.restart();
	}
}

sf::Clock PathState::GetNextTimer() const {
	return nextTimer;
}

void PathState::SetNextTimer(sf::Clock timer) {
	nextTimer = timer;
}

sf::RectangleShape PathState::GetBackground() const {
	return background;
}

void PathState::SetBackground(sf::RectangleShape bg) {
	background = bg;
}

sf::RectangleShape PathState::GetPathBox() const {
	return pathBox;
}

void PathState::SetPathBox(sf::RectangleShape pthBox) {
	pathBox = pthBox;
}

sf::RectangleShape PathState::GetGreyBox() const {
	return greyBox;
}

void PathState::SetGreyBox(sf::RectangleShape gryBox) {
	greyBox = gryBox;
}

sf::RectangleShape PathState::GetPathGreyBox() const {
	return pathGreyBox;
}

void PathState::SetPathGreyBox(sf::RectangleShape pthGreyBox) {
	pathGreyBox = pthGreyBox;
}

sf::Font PathState::GetFont() const {
	return trebuc;
}

void PathState::SetFont(sf::Font font) {
	trebuc = font;
}

sf::Text PathState::GetUserInputText() const {
	return userInput;
}

void PathState::SetUserInputText(sf::Text uInput) {
	userInput = uInput;
}

sf::Text PathState::GetPromptText() const {
	return prompt;
}

void PathState::SetPromptText(sf::Text p) {
	prompt = p;
}

sf::Text PathState::GetPathHeaderText() const {
	return pathHeader;
}

void PathState::SetPathHeaderText(sf::Text pthHeader) {
	pathHeader = pthHeader;
}

sf::String PathState::GetInput() {
	return input;
}

void PathState::SetInput(sf::String in) {
	input = in;
}

sf::Event PathState::GetEvent() const {
	return event;
}

void PathState::SetEvent(sf::Event e) {
	event = e;
}

Button PathState::GetNextButton() const {
	return next;
}

void PathState::SetNextButton(Button button) {
	next = button;
}
