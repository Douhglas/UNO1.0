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
	if (!deckTexture.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\UNOBACK.jpg")) {
		cout << "ERROR mainDeck texture" << endl;
	}
	deckShape.setPosition(position);
	deckShape.setSize(size);
	deckShape.setTexture(&deckTexture);
}

sf::RectangleShape DeckShape::getDeckShape()
{
	return deckShape;
}





