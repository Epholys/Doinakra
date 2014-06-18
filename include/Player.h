#ifndef PLAYER_H
#define PLAYER_H



#include<SFML/Graphics.hpp>


class Player
{
public:
	Player(float x=0, float y=0);

	void move(const sf::Vector2f& direction, const sf::Time& deltaTime);

	const sf::RectangleShape& paddle() const
		{
			return paddle_;
		}

private:
	sf::RectangleShape paddle_;

	static const float speed_;
};



#endif
