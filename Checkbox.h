#pragma once
#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "Button.h"

class Checkbox : public Button {
public:
	bool isButtonPressed(sf::RenderWindow& window) const;
};
#endif //CHECKBOX_H
