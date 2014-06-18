
#include<SFML/Graphics.hpp>

#include"Game.h"


//------------------------------------------------------------------------------
// *** constructor: ***

Game::Game()
	: window_(800, 600, "Doinakra",
			  sf::Style::Titlebar | sf::Style::Close),
	  player_(350, 550),
	  ball_(400, 300, 300.0f)
{
	for (int i=sf::Keyboard::A; i!=sf::Keyboard::KeyCount; ++i)
	{
		sf::Keyboard::Key k = static_cast<sf::Keyboard::Key>(i);
		isButtonPressed_[k] = false;
	}

	generate_bricks();
}


//------------------------------------------------------------------------------
// *** public function: ***

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;
	while (window_.isOpen())
	{
		timeSinceLastFrame = clock.restart();
		process_events();
		update(timeSinceLastFrame);
		render();
	}
}


//*------------------------------------------------------------------------------
// *** private functions: ***

void Game::process_events()
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window_.close();
			break;
		case sf::Event::KeyPressed:
			isButtonPressed_.at(event.key.code) = true;
			break;
		case sf::Event::KeyReleased:
			isButtonPressed_.at(event.key.code) = false;
			break;
		default:
			// do nothing
			break;
		}
	}
}

void Game::update(const sf::Time& deltaTime)
{
	sf::Vector2f playerDirection (0.0f, 0.0f);
	if (isButtonPressed_.at(sf::Keyboard::Right) |
		isButtonPressed_.at(sf::Keyboard::D))
	{
		playerDirection.x += 1.0f;
	}
	if (isButtonPressed_.at(sf::Keyboard::Left) |
		isButtonPressed_.at(sf::Keyboard::Q))
	{
		playerDirection.x -= 1.0f;
	}

	sf::FloatRect playerBounds = player_.paddle().getGlobalBounds();

	// detect collision of the paddle with the window
	if (window_.collideLeft(playerBounds) &&
		playerDirection.x < 0)
	{
		playerDirection = sf::Vector2f (0.0f, 0.0f);
	}
	if (window_.collideRight(playerBounds) &&
		playerDirection.x > 0)
	{
		playerDirection = sf::Vector2f (0.0f, 0.0f);
	}


	sf::FloatRect ballBounds = ball_.ball().getGlobalBounds();
	sf::Vector2f ballTransform (1.0f, 1.0f);
	sf::Vector2f ballDirection = ball_.direction();
	// detect collision of the ball with the window
	if (window_.collideLeft(ballBounds) &&
		ballDirection.x < 0)
	{
		ballTransform.x = -1.0f;
	}
	else if (window_.collideRight(ballBounds) &&
		ballDirection.x > 0)
	{
		ballTransform.x = -1.0f;
	}
	if (window_.collideUp(ballBounds))
	{
		ballTransform.y = -1.0f;
	}

	// detect collision of the ball with the paddle
	// and modify the trajectory of the ball accordingly
	sf::Vector2f ballAddition (0.0f, 0.0f);
	sf::FloatRect intersection;
	float ballAcceleration = 0.0f;
	if (playerBounds.intersects(ballBounds, intersection) &&
		ballDirection.y > 0)
	{
		float playerLength = playerBounds.width;
		float playerMiddle = playerBounds.left + playerLength/2;
		float collisionPointX = intersection.left;

		ballAddition.x = (2/playerLength)*(collisionPointX-playerMiddle);
		ballTransform.y = -1.0f;
		ballAcceleration = 5.0f;
	}

	// detect collision of the ball with bricks
	for (auto it = vBrick_.begin(); it != vBrick_.end(); ++it)
	{
		sf::FloatRect brickBounds ((*it).brick().getGlobalBounds());
		if (brickBounds.intersects(ballBounds, intersection))
		{
			Brick::collisionType collType = (*it).collide(intersection);
			if (collType == Brick::Horizontal)
			{
				ballTransform.y = -1.0f;
			}
			else
			{
				ballTransform.x = -1.0f;
			}
			
			if ((*it).life() <= 0)
			{
				vBrick_.erase(it);
			}
			break;
		}
	}

	ball_.change_direction(ballTransform);
	ball_.change_orientation(ballAddition);
	ball_.accelerate(ballAcceleration);

	player_.move(playerDirection, deltaTime);
	ball_.move(deltaTime);


	// close the window if victory of defeat:
	if (window_.collideDown(ballBounds) ||
		vBrick_.empty())
	{
		window_.close();
	}	   
}
 
void Game::render()
{
	window_.clear();

	window_.draw(player_.paddle());
	window_.draw(ball_.ball());
	for(size_t i=0; i<vBrick_.size(); ++i)
	{
		window_.draw(vBrick_.at(i).brick());
	}

	window_.display();
}

void Game::generate_bricks()
{
	for (int y=0; y<5; ++y)
	{
		for (int x=0; x<10; ++x)
		{
			vBrick_.push_back(Brick(x*77+10, y*22+10));
		}
	}
}
							 

