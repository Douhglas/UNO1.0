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

