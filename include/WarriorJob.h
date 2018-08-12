#pragma once
#include "Job.h"
class WarriorJob : public Job
{
public:
	WarriorJob();
	~WarriorJob();
	virtual void weakAttack();
	virtual void strongAttack();
};

