#pragma once
#include <string>
class Job
{
protected:
	std::string m_name;
public:
	virtual void weakAttack() = 0;
	virtual void strongAttack() = 0;
};

