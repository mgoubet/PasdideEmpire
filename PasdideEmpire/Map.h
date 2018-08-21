#pragma once
#include <vector>

#include "Character.h"
#include "Case.h"

class Map
{
private:
	std::vector<Character*> m_pnjs;
	std::vector<Case> m_cases;
public:
	Map();
	Map(std::vector<Character*> a_pnj, std::vector<Case> a_cases);
	~Map();
	void movePnj();
};

