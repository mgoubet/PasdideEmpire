#include "PlayerGUI.h"
#include "GameGUI.h"
#include <iostream>
void PlayerGUI::load(std::string a_filename)
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
		Animation walkingAnimationDown;
		walkingAnimationDown.setSpriteSheet(m_image);
		walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
		walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
		walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
		walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));
		m_animations.push_back(walkingAnimationDown);

		Animation walkingAnimationLeft;
		walkingAnimationLeft.setSpriteSheet(m_image);
		walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));
		m_animations.push_back(walkingAnimationLeft);

		Animation walkingAnimationRight;
		walkingAnimationRight.setSpriteSheet(m_image);
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));
		m_animations.push_back(walkingAnimationRight);

		Animation walkingAnimationUp;
		walkingAnimationUp.setSpriteSheet(m_image);
		walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
		walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
		walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
		walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));
		m_animations.push_back(walkingAnimationUp);

		m_animatedSprite = AnimatedSprite(sf::seconds(0.2), true, false);
		m_currentAnimation = &m_animations.at(0);
		std::cout << "test" << std::endl;
		
	}
}

PlayerGUI::PlayerGUI()
{
	load("Ressource/player.png");
	//getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);
	m_animatedSprite.setPosition(GameGUI::SCREEN_WIDTH / 2, GameGUI::SCREEN_HEIGHT / 2);
}


PlayerGUI::~PlayerGUI()
{
}

void PlayerGUI::update(sf::Time a_time)
{
	float l_speed = 80.f;
	bool l_noKeyWasPressed = true;

	// if a key was pressed set the correct animation and move correctly
	sf::Vector2f l_movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_currentAnimation = &m_animations.at(3);
		if (m_animatedSprite.getGlobalBounds().top > 0) {
			l_movement.y -= l_speed;
		}
		l_noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_currentAnimation = &m_animations.at(0);
		if (m_animatedSprite.getGlobalBounds().top + m_animatedSprite.getGlobalBounds().height < GameGUI::SCREEN_HEIGHT) {
			l_movement.y += l_speed;
		}
		l_noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_currentAnimation = &m_animations.at(1);
		if (m_animatedSprite.getGlobalBounds().left > 0) {
			l_movement.x -= l_speed;
		}
		l_noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_currentAnimation = &m_animations.at(2);
		if (m_animatedSprite.getGlobalBounds().left + m_animatedSprite.getGlobalBounds().width < GameGUI::SCREEN_WIDTH) {
			l_movement.x += l_speed;
		}
		l_noKeyWasPressed = false;
	}
	m_animatedSprite.play(*m_currentAnimation);
	m_animatedSprite.move(l_movement * a_time.asSeconds());
	if (l_noKeyWasPressed)
	{
		m_animatedSprite.stop();
	}
	m_animatedSprite.update(a_time);
}