#ifndef WINDOW_H
#define WINDOW_H



#include<SFML/Graphics.hpp>

class Window
{
public:
	Window(unsigned int width, unsigned int height,
		   const sf::String& title,
		   sf::Uint32 style = sf::Style::Default);

	bool isOpen()
		{ return window_.isOpen(); }

	bool pollEvent(sf::Event& ev)
		{ return window_.pollEvent(ev); }

	void close()
		{ window_.close(); }

	void clear(const sf::Color& color = sf::Color(0,0,0,255))
		{ window_.clear(color); }

	void draw (const sf::Drawable& drawable)
		{ window_.draw(drawable); }

	void display()
		{ window_.display(); }

	bool collideLeft(const sf::FloatRect& object) const;
	bool collideRight(const sf::FloatRect& object) const;
	bool collideUp(const sf::FloatRect& object) const;
	bool collideDown(const sf::FloatRect& object) const;

private:
	sf::RenderWindow window_;
};



#endif
