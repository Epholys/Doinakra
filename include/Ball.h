#ifndef BALL_H
#define BALL_H


#include<SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float x=0, float y=0, float s=200.0f);

	void move(const sf::Time& deltaTime);
	void change_direction(const sf::Vector2f& transform = sf::Vector2f(1.0f, 1.0f));
	void change_orientation(const sf::Vector2f& add = sf::Vector2f(0.0f, 0.0f));
	void accelerate(float acc = 0.0f);

	const sf::CircleShape& ball() const
		{
			return ball_;
		}

private:
	void normalize();

private:
	sf::CircleShape ball_;
	float speed_;
	sf::Vector2f direction_;
};


#endif
