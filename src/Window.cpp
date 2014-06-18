#include"SFML/Graphics.hpp"

#include"Window.h"


//------------------------------------------------------------------------------
// *** constructor: ***
Window::Window(unsigned int width, unsigned int height,
			   const sf::String& title,
			   sf::Uint32 style)
			   : window_(sf::VideoMode(width, height), title, style)
{
}


//------------------------------------------------------------------------------
// *** member functions: ***

bool Window::collideLeft(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(-51, 0, 50, window_.getSize().y));
}

bool Window::collideRight(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(window_.getSize().x-1, 0, 50, window_.getSize().y));
}

bool Window::collideUp(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(0, -51, window_.getSize().x, 50));
}

bool Window::collideDown(const sf::FloatRect& object) const
{
	return object.intersects(sf::FloatRect(0, window_.getSize().y-1, window_.getSize().x, 50));
}
