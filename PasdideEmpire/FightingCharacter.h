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
	~FightingCharacter();
	virtual int attack();
	virtual void takeDammage(int a_dammage);
	virtual void heal(int a_heal);
};

