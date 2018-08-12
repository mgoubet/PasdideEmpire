#pragma once
#include "Job.h"
#include "Projectile.h"
class ArcherJob
{
private:
	Projectile* m_weakArrow;
	Projectile* m_strongArrow;
public:
	ArcherJob();
	~ArcherJob();
	virtual void weakAttack();
	virtual void strongAttack();
};

