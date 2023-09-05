#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class DeckShape
{
private:

	int number;

	int color;

	sf::RectangleShape deckShape;
	

public:
	DeckShape();

	~DeckShape();

	void setColor(int _color);

	void setNumber(int _number);

	int getColor();

	int getNumber();

	void initDeckShape(sf::Vector2f position, sf::Vector2f size );

	void initDeckShape(string texture);

	sf::RectangleShape getDeckShape();

	void setTexture(sf::Texture* texture);

	void setTextureRectt(unsigned int xnumber, unsigned int ynumber,unsigned int x,unsigned int y);
	

};

