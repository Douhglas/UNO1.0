#include "Card.h"

Card::Card(sf::RenderWindow* window ) : Deck(window)
{
	initAmountOfCards();

	numberOfCardsToEat = 0;
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

	if (numberOfCardsToEat > 0) {
		numberOfCardsToEat--;
	}
}

void Card::getSpecialCardFromMainDeck(int color, int numcard, bool isLefTurn)
{
	if (numcard == 13 && cards[color][numcard] > 0) {

		setDeckPLayerTextureRect(color, numcard, isLefTurn);

		cards[0][numcard]--;
		cards[1][numcard]--;
		cards[2][numcard]--;
		cards[3][numcard]--;
		if (numberOfCardsToEat > 0) {
			numberOfCardsToEat--;
		}

	}
	if (numcard == 14 && cards[color][numcard] > 0) {

		setDeckPLayerTextureRect(5, 13, isLefTurn);

		cards[0][numcard]--;
		cards[1][numcard]--;
		cards[2][numcard]--;
		cards[3][numcard]--;
		if (numberOfCardsToEat > 0) {
			numberOfCardsToEat--;
		}

	}
}

void Card::initPileCard(int color, int numcard)
{
	initFirstPileCard(color, numcard);

	cards[color][numcard] --;
	

}

bool Card::isNotCardsToEat()
{
	if (numberOfCardsToEat == 0){
		return true;
}
	return false;
}

void Card::showCardsToEat(bool isLeftTurn,int atleastOneCard)
{
	cout << numberOfCardsToEat << endl;
	cout << atleastOneCard << endl;
	if (isLeftTurn) {
		cout << "Left Turn" << endl;
		
	}
	else {
		cout << "Right Turn" << endl;
	}
}

void Card::checkLostTurnCard(bool& isLeftTurn)
{
	if (isLeftTurn == true) {

		isLeftTurn = false;
    }
	else{

		isLeftTurn = true;
	}
}

void Card::checklimitPlusCard(int& plusCardLimitPerTurn)
{
	if (plusCardLimitPerTurn == 1) {
		plusCardLimitPerTurn = 0;
	}
}

void Card::checkStatementPlusCard(int& plusCardLimitPerTurn)
{
	if (getPile().getNumber() == 12) {
		numberOfCardsToEat += 2;
		plusCardLimitPerTurn = 1;

	}
	if(getPile().getNumber() == 16){
		numberOfCardsToEat += 4;
	}
}

void Card::init8CardsPerDeck()
{
	srand(time(NULL));
	int color;
	int number;
	while (AmountOfCardsInPLayerDeck(true) < 8 || AmountOfCardsInPLayerDeck(false) < 8) {

		color = rand() % 4;
		number = rand() % 15;
		if (AmountOfCardsInPLayerDeck(true) < 8) {
			getTypeCard(color,number,true);
		}
		color = rand() % 4;
		number = rand() % 15;

	    if (AmountOfCardsInPLayerDeck(false) < 8) {
				getTypeCard(color, number, false);
		}
	}
}

void Card::unoButtonPenalty(bool isleftTurn)
{
	srand(time(NULL));
	int color;
	int number;

	if (isleftTurn == false) {
		while (AmountOfCardsInPLayerDeck(false) < 3) {

			color = rand() % 4;
			number = rand() % 15;

			if (AmountOfCardsInPLayerDeck(false) < 3) {
				getTypeCard(color, number, false);
			}
		}
	}
	if (isleftTurn == true) {
		while (AmountOfCardsInPLayerDeck(true) < 3) {

			color = rand() % 4;
			number = rand() % 15;

			if (AmountOfCardsInPLayerDeck(true) < 3) {
				getTypeCard(color, number, true);
			}
		}
	}
}



