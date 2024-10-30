#include "Player.h"

Player::Player()
		:m_Speed(START_SPEED),
		m_Health(START_HEALTH),
		m_MaxHealth(START_HEALTH)
{
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(25, 25);
}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize) 
{
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;
	m_Arena = arena;
	m_TileSize = tileSize;
	m_Resolution = resolution;
}

void Player::resetPlayerStats() 
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

bool Player::hit(sf::Time) 
{
	return false;
}

sf::Time Player::getLastHitTime() 
{
	return sf::Time();
}

sf::FloatRect Player::getPosition() 
{
	return sf::FloatRect();
}

sf::Vector2f Player::getCenter() 
{
	return sf::Vector2f();
}

float Player::getRotation() 
{
	return 0.0f;
}

sf::Sprite Player::getSprite() 
{
	return sf::Sprite();
}

void Player::moveLeft() { m_LeftPressed = true; }
void Player::moveRight() { m_RightPressed = true; }
void Player::moveUp() { m_UpPressed = true;  }
void Player::moveDown() { m_DownPressed = true; }
void Player::stopLeft() { m_LeftPressed = false; }
void Player::stopRight() { m_RightPressed = false; }
void Player::stopUp() { m_UpPressed = false; }
void Player::stopDown() { m_DownPressed = false; }

void Player::update(float elapsedTime, sf::Vector2i mousePosition) 
{
	if (m_UpPressed) { m_Position.y -= m_Speed * elapsedTime; }
	if (m_DownPressed) { m_Position.y += m_Speed * elapsedTime; }
	if (m_RightPressed) { m_Position.x += m_Speed * elapsedTime;}
	if (m_LeftPressed) { m_Position.x -= m_Speed * elapsedTime; }
	m_Sprite.setPosition(m_Position);

	float angle = (atan2(mousePosition.y - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;
	m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed() 
{

}

void Player::upgradeHealth() 
{

}

void Player::increaseHealthLevel(int) 
{
	
}

int Player::getHealth() 
{
	return 0;
}