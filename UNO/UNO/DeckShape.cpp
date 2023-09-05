#include "DeckShape.h"
#include <iostream>
using namespace std;

DeckShape::DeckShape()
{
	color = 101;
	number = 101;
}

DeckShape::~DeckShape()
{
}

void DeckShape::setColor(int _color)
{
	color = _color;
}

void DeckShape::setNumber(int _number)
{
	number = _number;
}

int DeckShape::getColor()
{
	return color;
}

int DeckShape::getNumber()
{
	return number;
}

void DeckShape::initDeckShape(sf::Vector2f position, sf::Vector2f size)
{
	deckShape.setPosition(position);
	deckShape.setSize(size);

}

sf::RectangleShape DeckShape::getDeckShape()
{
	return deckShape;
}

void DeckShape::setTexture(sf::Texture* texture)
{
	deckShape.setTexture(texture);

}

void DeckShape::setTextureRectt(unsigned int xnumber, unsigned int ycolor, unsigned int x, unsigned int y)
{
	deckShape.setTextureRect(sf::IntRect(xnumber, ycolor, x, y));
}











