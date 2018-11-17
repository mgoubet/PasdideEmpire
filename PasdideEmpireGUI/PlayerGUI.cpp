#include "PlayerGUI.h"
#include "GameGUI.h"
#include "PlayingScreen.h"
#include "BackgroundGUI.h"
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
		
	}
}

bool PlayerGUI::collide()
{
	// TODO : adapt ca a tous les objets avec collision possible
	BackgroundGUI* l_tree = dynamic_cast<BackgroundGUI*>(PlayingScreen::getGameObjectManager().get("Tree"));
	if (l_tree != NULL) {
		sf::Rect<float> l_treeBB = l_tree->getBoundingRect();
		sf::Rect<float> l_player = m_animatedSprite.getGlobalBounds();
		if (l_treeBB.intersects(l_player)) {
			if (l_player.width > l_treeBB.top){
				std::cout << "BAS" << std::endl;
			}
			return true;
		}
	}
	return false;
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

void PlayerGUI::move(PlayerAction a_action, sf::Time a_time, float a_speed)
{
	sf::Vector2f l_movement(0.f, 0.f);
	if (!collide()) {
		bool l_noKeyWasPressed = true;
		switch (a_action) {
		case Up:
			m_currentAnimation = &m_animations.at(3);
			if (m_animatedSprite.getGlobalBounds().top > 0) {
				l_movement.y -= a_speed;
			}
			break;
		case Down:
			m_currentAnimation = &m_animations.at(0);
			if (m_animatedSprite.getGlobalBounds().top + m_animatedSprite.getGlobalBounds().height < GameGUI::SCREEN_HEIGHT) {
				l_movement.y += a_speed;
			}
			break;
		case Left:
			m_currentAnimation = &m_animations.at(1);
			if (m_animatedSprite.getGlobalBounds().left > 0) {
				l_movement.x -= a_speed;
			}
			break;
		case Right:
			m_currentAnimation = &m_animations.at(2);
			if (m_animatedSprite.getGlobalBounds().left + m_animatedSprite.getGlobalBounds().width < GameGUI::SCREEN_WIDTH) {
				l_movement.x += a_speed;
			}
			break;
		case None:
			l_noKeyWasPressed = false;
			break;
		}
		if (!l_noKeyWasPressed)
		{
			m_animatedSprite.stop();
		}
		//m_animatedSprite.move(l_movement * a_time.asSeconds());
	}
	else {
		// Todo : Ameliorer la remise en place si on est bloqué dans un objet
		switch (a_action) {
		case Right:
			m_currentAnimation = &m_animations.at(2);
			m_animatedSprite.setPosition(m_animatedSprite.getGlobalBounds().left - 0.5, m_animatedSprite.getGlobalBounds().top);
			break;
		case Left:
			m_currentAnimation = &m_animations.at(1);
			m_animatedSprite.setPosition(m_animatedSprite.getGlobalBounds().left + 0.5, m_animatedSprite.getGlobalBounds().top);
			break;
		case Down:
			m_currentAnimation = &m_animations.at(0);
			m_animatedSprite.setPosition(m_animatedSprite.getGlobalBounds().left, m_animatedSprite.getGlobalBounds().top - 0.5);
			break;
		case Up:
			m_currentAnimation = &m_animations.at(3);
			m_animatedSprite.setPosition(m_animatedSprite.getGlobalBounds().left, m_animatedSprite.getGlobalBounds().top + 0.5);
			break;
		case None:
			break;
		}
	}
	m_animatedSprite.move(l_movement * a_time.asSeconds());
}

void PlayerGUI::update(sf::Time a_time)
{
	m_animatedSprite.play(*m_currentAnimation);
	m_animatedSprite.update(a_time);
}