#pragma once
#include "Deck.h"
#include <time.h>

class Card: public Deck
{
private:

	static const int AMOUNT_OF_COLORS = 4;

	static const int AMOUNT_OF_CARDS = 15;

	int cards[AMOUNT_OF_COLORS][AMOUNT_OF_CARDS];

	int numberOfCardsToEat;
	
public:

	Card(sf::RenderWindow* window);

	~Card();

	int getNumberOfCardsToEat();

	void initAmountOfCards();

	void getTypeCard(int color, int numcard, bool isLeftturn);
	
	void getNormalCardFromMainDeck(int color, int numcard, bool isLefTurn);

	void getSpecialCardFromMainDeck(int color, int numcard, bool isLefTurn);

	void initPileCard(int color , int numcard);

	void checkStatementPlusCard(int& plusCardLimitPerTurn);

	bool isNotCardsToEat();

	void showCardsToEat(bool isLeftTurn, int atleastOneCard);

	void checklimitPlusCard(int& plusCardLimitPerTurn);

	void checkLostTurnCard(bool& isLeftTurn);

	void init8CardsPerDeck();

	void unoButtonPenalty(bool isleftTurn);
};

