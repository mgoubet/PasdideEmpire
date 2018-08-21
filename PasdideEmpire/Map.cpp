#include "stdafx.h"
#include "Map.h"


Map::Map()
{
}

Map::Map(std::vector<Character*> a_pnj, std::vector<Case> a_cases)
{
	m_pnjs = a_pnj;
	m_cases = a_cases;
}


Map::~Map()
{
}

void Map::movePnj()
{
	for (int i = 0; i < m_pnjs.size(); i++) {
		m_pnjs.at(i)->move(1, 1);
	}
}
