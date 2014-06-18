#include"Brick.h"


//------------------------------------------------------------------------------
// *** constructor: ***

Brick::Brick (float x, float y, int l)
	: brick_(sf::Vector2f(75, 20)),
	  life_(l)
{
	brick_.setPosition(x, y);
	brick_.setFillColor(sf::Color::Red);
}


//------------------------------------------------------------------------------
// *** public function: ***

Brick::collisionType Brick::collide (const sf::FloatRect& collision)
{
	--life_;


	sf::Vector2f collisionTop 
		(collision.left + collision.width/2,
		 collision.top);

	sf::Vector2f brickPosition = brick_.getPosition();
	float brickWidth = brick_.getSize().x;
	float brickHeight = brick_.getSize().y;

	if (collisionTop.x < brickPosition.x + 19*brickWidth/20 &&
		collisionTop.x > brickPosition.x + 1*brickWidth/20 &&
		collisionTop.y < brickPosition.y + brickHeight &&
		collisionTop.y > brickPosition.y)
	{
		return Horizontal;
	}
	else
	{
		return Vertical;
	}
}

