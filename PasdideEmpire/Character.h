#pragma once
#include <vector>
#include <string>
class Character
{
protected:
	int m_x;
	int m_y;
	std::string m_name;
public:
	Character();
	Character(int a_x, int a_y, std::string a_name);
	virtual void move(int a_x, int a_y) = 0;
	inline int getX() { return m_x; }
	inline int getY() { return m_y; }
};
