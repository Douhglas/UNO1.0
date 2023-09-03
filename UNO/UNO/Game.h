#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::Texture optionTexture1;
	sf::Texture optionTexture2;
	sf::Texture optionTexture3;
	sf::Texture optionTexture4;
	sf::Texture optionTexture5;
public:
	Game();
	~Game();
	sf::Texture getOptionTexture1();
	void initTextures();

};