#pragma once
#include <vector>
#include <string>
class Character
{
private:
	std::vector<int> m_coordinate;
	std::string m_name;
public:
	virtual void move() = 0;
};

