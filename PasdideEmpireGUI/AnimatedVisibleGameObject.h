#pragma once
#include "VisibleGameObject.h"
#include "AnimatedSprite.h"

class AnimatedVisibleGameObject : public VisibleGameObject
{
protected:
	AnimatedSprite m_animatedSprite;
	Animation* m_currentAnimation;
	//todo : passer ca en map
	std::vector<Animation> m_animations;
public:
	AnimatedVisibleGameObject();
	~AnimatedVisibleGameObject();

	void update(sf::Time a_time) = 0;
	void draw(sf::RenderWindow & a_window);
	inline AnimatedSprite getAnimatedSprite() { return m_animatedSprite; }
};