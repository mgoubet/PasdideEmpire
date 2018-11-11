#include "GameGUI.h"
#include "MainMenu.h"

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

const GameObjectManager& GameGUI::getGameObjectManager()
{
	return GameGUI::m_gameObjectManager;
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
			m_mainWindow.clear(sf::Color(0, 0, 0));

			m_gameObjectManager.updateAll();
			m_gameObjectManager.drawAll(m_mainWindow);
		
			m_mainWindow.display();

			if (l_currentEvent.type == sf::Event::Closed) {
				m_gameState = GameGUI::Exiting;
			}

			if (l_currentEvent.type == sf::Event::KeyPressed)
			{
				if (l_currentEvent.key.code == sf::Keyboard::Escape) {
					showMenu();
				}
			}

			break;
		}
	}
}


void GameGUI::showMenu()
{
	MainMenu l_mainMenu;
	MainMenu::MenuResult l_result = l_mainMenu.Show(m_mainWindow);
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

GameGUI::GameState GameGUI::m_gameState = Uninitialized;
sf::RenderWindow GameGUI::m_mainWindow;
GameObjectManager GameGUI::m_gameObjectManager;