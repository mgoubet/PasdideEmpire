#include "stdafx.h"
#include "Case.h"


Case::Case()
{
}


Case::~Case()
{
}

std::vector<int> Case::getCoordinate()
{
	//TODO Depend coordMax
	return std::vector<int>();
}

std::vector<int> Case::getPosition()
{
	return m_position;
}

void Case::setPosition(std::vector<int> a_position)
{
	m_position = a_position;
}
