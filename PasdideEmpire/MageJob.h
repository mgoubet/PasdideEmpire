#pragma once
#include "Job.h"
#include "AttackOnEveryone.h"
class MageJob
{
private:
	AttackOnEveryone* m_aoe;
public:
	MageJob();
	~MageJob();
	virtual void weakAttack();
	virtual void strongAttack();
};

