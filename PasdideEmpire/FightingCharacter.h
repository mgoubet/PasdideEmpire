#pragma once
#include "Job.h"
#include "Character.h"

class FightingCharacter : public Character
{
protected:
	Job* m_job;
	int m_hpMax;
	int m_currentHp;
	int m_level;
	
public:
	FightingCharacter();
	FightingCharacter(int a_x, int a_y, std::string a_name, Job* a_job, int a_hpMax, int a_currentHp, int a_lvl);
	~FightingCharacter();
	virtual int attack();
	virtual void takeDammage(int a_dammage);
	virtual void heal(int a_heal);
};

