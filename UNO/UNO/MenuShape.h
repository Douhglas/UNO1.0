#pragma once
#include <SFML/Graphics.hpp>
class MenuShape
{
private:
	sf::RectangleShape buttonShape;
	sf::Texture buttonTexture;
	sf::Text text;

public:
	MenuShape();
	~MenuShape();
	void initButtons(sf::Vector2f size, sf::Vector2f buttonPosition, sf::Texture texture );
	void initButtons(sf::Font font, sf::Vector2f buttonPosition, std::string text);
	sf::RectangleShape getButtonShape();
	sf::Text getText();
};
