#pragma once
#include "Job.h"
class SkeletonJob : public Job
{
public:
	SkeletonJob();
	~SkeletonJob();
	virtual void weakAttack();
	virtual void strongAttack();
};

