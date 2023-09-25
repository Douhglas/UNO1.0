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

void MenuShape::initButtons(sf::Font font, sf::Vector2f buttonPosition, std::string text)
{
	this->text.setFont(font);
	this->text.setPosition(buttonPosition);
	this->text.setString(text);

}

sf::RectangleShape MenuShape::getButtonShape()
{
	return buttonShape;
}

sf::Text MenuShape::getText()
{
	return text;
}
