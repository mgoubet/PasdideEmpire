#pragma once
#include "Map.h"
class Game
{
private:
	Map m_currentMap;
	Character* m_mainPlayer;
public:
	Game();
	~Game();

	void changeMap(Map a_map);
};

