#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject()
	: m_isLoaded(false)
{
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::load(std::string a_filename)
{
	if (m_image.loadFromFile(a_filename) == false)
	{
		m_filename = "";
		m_isLoaded = false;
	}
	else
	{
		m_isLoaded = true;
		m_filename = a_filename;
		m_sprite.setTexture(m_image);
	}
}

void VisibleGameObject::draw(sf::RenderWindow & a_renderWindow)
{
	if (m_isLoaded)
	{
		a_renderWindow.draw(m_sprite);
	}
}

void VisibleGameObject::setPosition(float a_x, float a_y)
{
	if (m_isLoaded)
	{
		m_sprite.setPosition(a_x, a_y);
	}
}

sf::Vector2f VisibleGameObject::getPosition() const
{
	if (m_isLoaded)
	{
		return m_sprite.getPosition();
	}
	return sf::Vector2f();
}

float VisibleGameObject::getHeight() const
{
	return m_sprite.getLocalBounds().height;
}

float VisibleGameObject::getWidth() const
{
	return m_sprite.getLocalBounds().width;
}

sf::Rect<float> VisibleGameObject::getBoundingRect() const
{
	return m_sprite.getGlobalBounds();
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return m_sprite;
}

bool VisibleGameObject::isLoaded() const
{
	return m_isLoaded;
}