#pragma once
#include <vector>
#include <string>
class Character
{
private:
	std::vector<int> m_coordinate;
	std::string m_name;
public:
	virtual void move(int a_x, int a_y) = 0;
};

