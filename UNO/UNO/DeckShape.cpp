#include "DeckShape.h"
#include <iostream>
using namespace std;

DeckShape::DeckShape()
{
}

DeckShape::~DeckShape()
{
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

void DeckShape::setTextureRect(unsigned int xnumber, unsigned int ycolor, unsigned int x, unsigned int y)
{
	deckShape.setTextureRect(sf::IntRect(xnumber, ycolor, x, y));
}











