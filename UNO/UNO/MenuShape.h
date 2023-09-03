#pragma once
#include <SFML/Graphics.hpp>
class MenuShape
{
private:
	sf::RectangleShape buttonShape;
	sf::Texture buttonTexture;

public:
	MenuShape();
	~MenuShape();
	void initButtons(sf::Vector2f size, sf::Vector2f buttonPosition, sf::Texture texture);
	sf::RectangleShape getButtonShape();
};
