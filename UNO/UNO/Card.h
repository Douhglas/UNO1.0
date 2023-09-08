#pragma once
#include "Deck.h"

class Card: public Deck
{
private:

	static const int AMOUNT_OF_COLORS = 4;

	static const int AMOUNT_OF_CARDS = 15;

	int colorCards = 4;

	int plusFourCards = 4;

	int cards[AMOUNT_OF_COLORS][AMOUNT_OF_CARDS];

	
public:

	Card(sf::RenderWindow* window);

	~Card();

	void initAmountOfCards();

	void getTypeCard(int color, int numcard, bool isLeftturn);
	
	void getNormalCardFromMainDeck(int color, int numcard, bool isLefTurn);

	void getSpecialCardFromMainDeck(int color, int numcard, bool isLefTurn);

	void initPileCard(int color , int numcard);

	

};

