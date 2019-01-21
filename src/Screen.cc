#include "Screen.hh"
#include "SFML/Graphics.hpp"

/// Constructor
//---------------------------------------------------
Screen::Screen(uint16_t h, uint16_t w): _h(h), _w(w)
//---------------------------------------------------
{
	_win = new sf::RenderWindow(sf::VideoMode(_h , _w), "PACMAIN, pacman-like game");
	_win->setIcon( sfml_icon.width,  sfml_icon.height,  sfml_icon.pixel_data );
}

/// Render window
//------------------------
void Screen::render()
//------------------------
{
	_win->display();
	_win->clear();
}

/// Draw wall at (x,y) position
//------------------------------
void Screen::wall(int x, int y)
//------------------------------
{
	sf::RectangleShape r(sf::Vector2f(20, 20));
	r.setFillColor(sf::Color::Blue);
	r.setPosition(y * 20 + 20, x * 20 + 20);
	_win->draw(r);
}

/// Draw a pacgum at (x,y) position
//------------------------------
void Screen::pacgum(int x, int y)
//------------------------------
{
	sf::RectangleShape r(sf::Vector2f(5, 5));
	r.setFillColor(sf::Color::Yellow);
	r.setPosition(y * 20 + 30, x * 20 + 30);
	_win->draw(r);
}

/// Draw pacman at (x,y) position
//------------------------------
void Screen::pacman(int x, int y)
//------------------------------
{
	sf::CircleShape shape(10);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(y * 20 + 22, x * 20 + 22);
	_win->draw(shape);
}

/// Draw Dumb Ghost at (x,y) position
//------------------------------
void Screen::ghostdumb(int x, int y)
//------------------------------
{
	sf::CircleShape shape(10);
	shape.setFillColor(sf::Color::White);
	shape.setPosition(y * 20 + 22, x * 20 + 22);
	_win->draw(shape);
}

/// Draw Smart Ghost at (x,y) position
//------------------------------
void Screen::ghostsmart(int x, int y)
//------------------------------
{
	sf::CircleShape shape(10);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(y * 20 + 22, x * 20 + 22);
	_win->draw(shape);
}

/// Draw Super gum at (x,y) position
//------------------------------
void Screen::supergum(int x, int y)
//------------------------------
{
	sf::CircleShape r(10, 3);
	r.setFillColor(sf::Color::Yellow);
	r.setPosition(y * 20 + 22, x * 20 + 22);
	_win->draw(r);
}

// Draw msg at (x,y) position 
//------------------------------
void Screen::put_msg(std::string s,int x, int y, int size, sf::Color c)
//------------------------------
{
	sf::Font font;
	std::string font_file("assets/ComicNeue-Angular-Bold.ttf");
	if (!font.loadFromFile(font_file))
	{	
		std::cout << "Error on loading file: "+ font_file << std::endl;
		exit(1);
	}
	sf::Text text;
	text.setFont(font);
	// set the string to display
	text.setString(s);
	// set the character size
	text.setCharacterSize(size); // in pixels, not points!
	// set the color
	text.setFillColor(c);
	
	text.setPosition(x, y);
	_win->draw(text);
}
