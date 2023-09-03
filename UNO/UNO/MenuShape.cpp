#include "MenuShape.h"

MenuShape::MenuShape()
{
}

MenuShape::~MenuShape()
{
}

void MenuShape::initButtons(sf::Vector2f size, sf::Vector2f buttonPosition, sf::Texture texture)
{
	buttonTexture = texture;
	buttonShape.setSize(size);
	buttonShape.setPosition(buttonPosition);
	buttonShape.setTexture(&buttonTexture);
}

sf::RectangleShape MenuShape::getButtonShape()
{
	return buttonShape;
}