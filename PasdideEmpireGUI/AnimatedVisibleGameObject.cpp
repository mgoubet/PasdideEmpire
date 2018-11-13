#include "AnimatedVisibleGameObject.h"



AnimatedVisibleGameObject::AnimatedVisibleGameObject()
{
}


AnimatedVisibleGameObject::~AnimatedVisibleGameObject()
{
}

void AnimatedVisibleGameObject::draw(sf::RenderWindow & a_window)
{
	if (m_isLoaded)
	{
		a_window.draw(m_animatedSprite);
	}
}
