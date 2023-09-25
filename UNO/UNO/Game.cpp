#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	initTextures();

}

Game::~Game()
{
}

sf::Texture Game::getOptionTexture1()
{
	return optionTexture1;
}

sf::Texture Game::getOptionTexture2()
{
	return optionTexture2;
}

sf::Texture Game::getOptionTexture3()
{
	return optionTexture3;
}

sf::Texture Game::getOptionTexture4()
{
	return optionTexture4;
}

sf::Texture Game::getOptionTexture5()
{
	return optionTexture5;
}

void Game::initTextures()
{
	if (!optionTexture1.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\SinglePlayer.png")) {
		cout << " ERROR optionTexture1" << endl;
	}
	if (!optionTexture2.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\Multiplayer.png")) {
		cout << " ERROR optionTexture1" << endl;
	}
	if (!optionTexture3.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\Play.png")) {
		cout << " ERROR optionTexture1" << endl;
	}
	if (!optionTexture4.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\Winner.png")) {
		cout << " ERROR optionTexture1" << endl;
	}
	if (!optionTexture5.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\Winner.png")) {
		cout << " ERROR optionTexture1" << endl;
	}
}

