#pragma once
#include "Card.h"
class Rule
{
private:
	bool isplusTwo;
	bool isplusFour;
	bool isanyCard;


public:

	void checkMinimumCardsPerTurn();
	void throwAnyCard();
	void throwCompatibleCard();

};

//Puede ordernar las imagenes y los dll en carpetas, no pesan casi nada y facilitan la comprension y orden