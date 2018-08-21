#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

Game::Game(Map a_map, Character * a_mainPlayer)
{
	m_currentMap = a_map;
	m_mainPlayer = a_mainPlayer;
}


Game::~Game()
{
}

void Game::changeMap(Map a_map)
{
	m_currentMap = a_map;
}
