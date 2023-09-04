#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class DeckShape
{
private:

	sf::Vector2i number;

	sf::RectangleShape deckShape;
	

public:
	DeckShape();

	~DeckShape();

	void initDeckShape(sf::Vector2f position, sf::Vector2f size );

	void initDeckShape(string texture);

	sf::RectangleShape getDeckShape();

	void setTexture(sf::Texture* texture);

	void setTextureRect(unsigned int xnumber, unsigned int ynumber,unsigned int x,unsigned int y);
	

};

