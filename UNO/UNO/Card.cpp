#include "Card.h"

Card::Card(sf::RenderWindow* window) : Deck(window)
{
	
}

Card::~Card()
{
}

void Card::initAmountOfCards()
{
	for (int i = 0; i < AMOUNT_OF_COLORS; i++) {
		for (int j = 0; j < AMOUNT_OF_CARDS; j++) {

			cards[i][j] = 2;

			if (j == 0 || j == 13 || j == 14) {

				cards[i][j] = 1;

			}
			else {

				cards[i][j] = 2;

			}

		}
	}
}


