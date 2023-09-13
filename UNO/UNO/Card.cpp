#include "Card.h"

Card::Card(sf::RenderWindow* window ) : Deck(window)
{
	initAmountOfCards();
}

Card::~Card()
{
}

void Card::initAmountOfCards()
{
	for (int i = 0; i < AMOUNT_OF_COLORS; i++) {
		for (int j = 0; j < AMOUNT_OF_CARDS; j++) {

			cards[i][j] = 2;

			if (j == 0 ) {

				cards[i][j] = 1;

			}
			if (j == 13 || j == 14){

				cards[i][j] = 4;
			}
			else {

				cards[i][j] = 2;

			}

		}
	}
}

void Card::getTypeCard(int color, int numcard, bool isLeftturn)
{
	
	if (numcard == 13 || numcard == 14) {

		getSpecialCardFromMainDeck(color, numcard,isLeftturn);

	}
	else {
		if (cards[color][numcard] > 0) {

			getNormalCardFromMainDeck(color, numcard,isLeftturn);

		}
	}
}

void Card::getNormalCardFromMainDeck(int color, int numcard, bool isLefTurn)
{
	setDeckPLayerTextureRect(color, numcard, isLefTurn);

	cards[color][numcard]--;
}

void Card::getSpecialCardFromMainDeck(int color, int numcard, bool isLefTurn)
{
	if (numcard == 13 && cards[color][numcard] > 0) {

		setDeckPLayerTextureRect(color, numcard, isLefTurn);

		cards[0][numcard]--;
		cards[1][numcard]--;
		cards[2][numcard]--;
		cards[3][numcard]--;

	}
	if (numcard == 14 && cards[color][numcard] > 0) {

		setDeckPLayerTextureRect(5, 13, isLefTurn);

		cards[0][numcard]--;
		cards[1][numcard]--;
		cards[2][numcard]--;
		cards[3][numcard]--;


	}
}

void Card::initPileCard(int color, int numcard)
{
	initFirstPileCard(color, numcard);

	cards[color][numcard] --;

}



