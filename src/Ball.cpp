#include"Ball.h"


//------------------------------------------------------------------------------
// *** constructor: ***

Ball::Ball(float x, float y, float s)
	: ball_ (8), speed_(s), direction_(0.75f, 1.0f)
{
	ball_.setPosition(x, y);
	normalize();
}


//------------------------------------------------------------------------------
// *** public function: ***

void Ball::move (const sf::Time& deltaTime)
{
	ball_.move (direction_ * speed_ * deltaTime.asSeconds());
}

void Ball::change_direction(const sf::Vector2f& transform)
{
	direction_.x *= transform.x;
	direction_.y *= transform.y;
	normalize();
}

void Ball::change_orientation(const sf::Vector2f& add)
{
	direction_.x += add.x;
	direction_.y += add.y;
	normalize();
}

void Ball::accelerate(float acc)
{
	speed_ += acc;
}


//------------------------------------------------------------------------------
// *** private function: ***

void Ball::normalize()
{
	float dx = direction_.x;
	float dy = direction_.y;
	float length = float(sqrt(dx*dx + dy*dy));
	direction_ = direction_ / length;
}
