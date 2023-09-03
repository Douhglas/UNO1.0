#pragma once
#include <SFML/Graphics.hpp>
class DeckShape
{
private:
	int color;
	int number;
	sf::RectangleShape deckShape;
	sf::Texture deckTexture;

public:
	DeckShape();
	~DeckShape();
	void initDeckShape(sf::Vector2f position, sf::Vector2f size );
	sf::RectangleShape getDeckShape();
	void setDeckShapeTexture();

};

