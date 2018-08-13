#pragma once
#include "FightingCharacter.h"
#include "Inventory.h"
class PlayerCharacter : public FightingCharacter
{
private:
	std::vector<std::string> m_classAvailable;
	bool m_isInCombat;
	Inventory m_inventory;
	int m_expMax;
	int m_currentExp;
public:
	PlayerCharacter();
	~PlayerCharacter();
	void changeJob();
	virtual void move(int a_x, int a_y);
};

