#include "GameGUI.h"
#include "MainMenu.h"
#include "PlayingScreen.h"
void GameGUI::start(void)
{
	if (m_gameState != Uninitialized)
		return;

	m_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pasdide Empire");

	//_mainWindow.setFramerateLimit(60);

	m_gameState = GameGUI::ShowingMenu;


	while (!isExiting())
	{
		gameLoop();
	}

	m_mainWindow.close();
}

bool GameGUI::isExiting()
{
	if (m_gameState == GameGUI::Exiting)
		return true;
	else
		return false;
}


sf::RenderWindow& GameGUI::getWindow()
{
	return m_mainWindow;
}

const sf::Event& GameGUI::getInput()
{
	sf::Event l_currentEvent;
	m_mainWindow.pollEvent(l_currentEvent);
	return l_currentEvent;
}

void GameGUI::gameLoop()
{
	sf::Event l_currentEvent;
	m_mainWindow.pollEvent(l_currentEvent);


	switch (m_gameState)
	{
		case GameGUI::ShowingMenu:
		{
			showMenu();
			break;
		}
		case GameGUI::Playing:
		{
			showPlayingScreen();
			break;
		}
	}
}


void GameGUI::showMenu()
{
	MainMenu l_mainMenu;
	MainMenu::MenuResult l_result = l_mainMenu.show(m_mainWindow);
	switch (l_result)
	{
		case MainMenu::Exit:
			m_gameState = Exiting;
			break;
		case MainMenu::Play:
			m_gameState = Playing;
			break;
	}
}

void GameGUI::showPlayingScreen()
{
	PlayingScreen l_playingScreen;
	PlayingScreen::PlayingResult l_result = l_playingScreen.show(m_mainWindow);
	switch (l_result)
	{
		case PlayingScreen::Exit:
			m_gameState = Exiting;
			break;
		case PlayingScreen::ReturnMenu:
			m_gameState = ShowingMenu;
			break;
	}
}

GameGUI::GameState GameGUI::m_gameState = Uninitialized;
sf::RenderWindow GameGUI::m_mainWindow;
