#ifndef GAME_H
#define GAME_H


#include<vector>
#include<map>
#include<SFML/Graphics.hpp>
#include"Window.h"
#include"Player.h"
#include"Ball.h"
#include"Brick.h"

class Game
{
public:
	Game();

	void run();

private:
	void process_events();
	void update(const sf::Time& deltaTime);
	void render();
	
	void generate_bricks();

private:
	Window window_;

	Player player_;
	Ball ball_;
	std::vector<Brick> vBrick_;

	std::map<sf::Keyboard::Key, bool> isButtonPressed_;
};


#endif
