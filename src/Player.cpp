#include<iostream>

#include<SFML/Graphics.hpp>

#include"Player.h"


//------------------------------------------------------------------------------
// *** static attributes: ***

// in pixel / second
const float Player::speed_ = 300.0f;


//------------------------------------------------------------------------------
// *** constructor: ***

Player::Player(float x, float y)
	: paddle_(sf::Vector2f(100.0f, 20.0f))
{
	paddle_.setPosition(x, y);
}


//------------------------------------------------------------------------------
// *** public function: ***

void Player::move(const sf::Vector2f& direction, const sf::Time& deltaTime)
{
	paddle_.move(direction * speed_ * deltaTime.asSeconds());
}
