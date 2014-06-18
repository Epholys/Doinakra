#ifndef BRICK_H
#define BRICK_H


#include<SFML/Graphics.hpp>

class Brick
{
public:
	enum collisionType
	{
		Horizontal, Vertical
	};

public:
	Brick (float x=0, float y=0, int l=1);

	collisionType collide (const sf::FloatRect& collision);

	int life () const { return life_; }
	const sf::RectangleShape& brick () const { return brick_; }

private:
	sf::RectangleShape brick_;

	int life_;
};


#endif
