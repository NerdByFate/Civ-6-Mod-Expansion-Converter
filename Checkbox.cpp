#include "Checkbox.h"

bool Checkbox::isButtonPressed(sf::RenderWindow& window) const {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= getPosition().x - ((window.getView().getCenter().x - (window.getView().getSize().x/2)) - (window.getView().getViewport().left*window.getSize().x)) && sf::Mouse::getPosition(window).x <= getPosition().x + GetWidth() - ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) - (window.getView().getViewport().left*window.getSize().x)) && sf::Mouse::getPosition(window).y >= getPosition().y - ((window.getView().getCenter().y - (window.getView().getSize().y / 2)) - (window.getView().getViewport().top*window.getSize().y)) && sf::Mouse::getPosition(window).y <= getPosition().y + GetHeight() - ((window.getView().getCenter().y - (window.getView().getSize().y / 2)) - (window.getView().getViewport().top*window.getSize().y))) {
		return true;
	}
	else {
		return false;
	}
}
