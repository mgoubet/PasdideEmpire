#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjectManager.h"

class GameGUI
{
private:
	static bool isExiting();
	static void gameLoop();

	static void showMenu();
	static void showPlayingScreen();

	enum GameState {
		Uninitialized, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState m_gameState;
	static sf::RenderWindow m_mainWindow;
	
public:
	static void start();
	static sf::RenderWindow& getWindow();
	const static sf::Event& getInput();

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
};

