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
	PlayerCharacter(int a_x, int a_y, std::string a_name, Job* a_currentJob, int a_hpMax, int a_currentHp, int a_lvl, int a_expMax, int a_currentExp, Inventory a_inv);
	~PlayerCharacter();
	void changeJob();
	virtual void move(int a_x, int a_y);
};

