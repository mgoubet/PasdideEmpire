#include "stdafx.h"
#include "Character.h"

Character::Character()
{
}

Character::Character(int a_x, int a_y, std::string a_name)
{
	m_x = a_x;
	m_y = a_y;
	m_name = a_name;
}
