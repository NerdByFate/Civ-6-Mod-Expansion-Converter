#include "State.h"

State::State() {
	positionSet = false;
	//Insert private data initialization here
}

int State::Render(sf::RenderWindow& window) {
	window.clear();
	//Insert Draw Code Here
	window.display();

	return 0;
}

void State::HandleEvents(sf::RenderWindow& window) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

sf::Event State::GetEvent() const {
	return event;
}

void State::SetEvent(sf::Event e) {
	event = e;
}

bool State::GetPositionSet() const {
	return positionSet;
}

void State::SetPositionSet(bool posSet) {
	positionSet = posSet;
}
