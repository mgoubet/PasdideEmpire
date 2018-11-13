#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow & window);
	virtual void update(sf::Time a_time) = 0;

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual float getWidth() const;
	virtual float getHeight() const;

	virtual sf::Rect<float> getBoundingRect() const;
	virtual bool isLoaded() const;

protected:
	sf::Sprite& getSprite();
	bool m_isLoaded;
	sf::Sprite  m_sprite;
	sf::Texture m_image;
	std::string m_filename;

};
