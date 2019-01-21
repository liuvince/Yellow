#include <iostream>
#include <istream>
#include <string>
#include "Game.hh"
#include "Player.hh"
#include "Cell.hh"
#include "Screen.hh"
#include "Pacgum.hh"
#include "Pacman.hh"
#include "SFML/Graphics.hpp"
#include "GhostDumb.hh"
#include "GhostSmart.hh"
#include "SuperGum.hh"
#include <time.h> 

//-----------------------------------------------------------
Game::Game(): _screen(800, 400), _cache(NONE), _easy(true), _state(STATE_START)
//-----------------------------------------------------------
{
	reset_map();
}

/// Destructor
//--------------------------
Game::~Game()
//--------------------------
{
	for(auto & cell: _grid)
	{
		cell.del_obj();
		cell.set_obj(NULL);
	}
	for(auto & ghost: _ghosts)
	{
		delete ghost;
	}
}

/// Run game
//---------------------------
void Game::run()
//---------------------------
{
	while (_screen.is_open() )
	{
		switch ( _state )
		{
			case STATE_START: menu();
					break;
			case STATE_GAME: play();
					break;
			case STATE_DEAD: dead();
					break;
			case STATE_END: end();
					std::cout << (*this);
					break;
			default: 
					break;		
		}
	}
}
/// Menu of the game
//-----------------------------
void Game::menu()
//-----------------------------
{
	menu_event();
	menu_logic();
	menu_render();

}

// Play state
//----------------------------------------
void Game::play()
//----------------------------------------
{
	play_event();
	play_logic();
	show();
	play_check();

}

// Dead state
//-----------------------------------
void Game::dead()
//-----------------------------------
{	
	dead_event();
	dead_render();
	dead_check();
}


// End state
//--------------------------
void Game::end()
//--------------------------
{
	_screen.close();
	_state = STATE_END;
}


/// Reset characters in the map
//-------------------------
void Game::reset_char()
//-------------------------
{
	// Delete
	for(auto & ghost: _ghosts)
	{
		delete ghost;
	}	
	_ghosts.clear();
	// Reload characters
	std::ifstream cha("assets/characters.data");
	load_characters(cha);
	_cache = NONE;
	_p.set_direction(UP);
}

//-----------------------
void Game::reset_map()
//-----------------------
{
	std::ifstream map("assets/map.data");
	load_map(map);
}

/// Load useful data to play the game (map)
//------------------------------------------
void Game::load_map(std::ifstream &file)
//------------------------------------------
{
	char singleChar;
	std::string hstring, wstring;	

	// Read width and height of the map
	file >> hstring;
	file >> wstring;
	_h = std::stoi(hstring);
	_w = std::stoi(wstring);

	file.get(singleChar);
	// Get the map from the input file
	for (int i=0; i < _h; ++i)
	{
		for (int j=0; j < _w; ++j)
		{
			// Get one single character
			file.get(singleChar);
			// Create a new cell
			_grid.push_back(Cell(Point(i,j)));
			if (singleChar == '=')
			{
				_grid[j+_w*i].set_wall(true);
			}
			if (singleChar == '*')
			{
				_grid[j+_w*i].set_obj(new Pacgum(10));			
			}
			if (singleChar == '.')
			{
				_grid[j+_w*i].set_obj(new Supergum(100));			
			}
		}
	}
}

/// Load useful data to play the game (entities' position)
//----------------------------------------------
void Game::load_characters(std::ifstream &file)
//----------------------------------------------
{
	std::string xstring, ystring;
	// Read x, and y for player origin position
	file >> xstring;
	file >> ystring;
	_p.set_pos( std::stoi(xstring), std::stoi(ystring) );


	file >> xstring;
	file >> ystring;
	for (int i = 0; i < 4; i++)
	{
		file >> xstring;
		file >> ystring;
		if (_easy) // easy
		{
			_ghosts.push_back(new GhostDumb( Point(std::stoi(xstring), std::stoi(ystring)), LEFT ));
		}
		else // hard
		{
			_ghosts.push_back(new GhostSmart( Point(std::stoi(xstring), std::stoi(ystring)), LEFT ));
		}
	}
}


static sf::Color c1 = sf::Color::Yellow;
static sf::Color c2 = sf::Color::White;
static sf::Color ctemp;

/// Event of menu state
//-------------------------------------
void Game::menu_event()
//-------------------------------------
{
	sf::Event event;
	while (_screen.pollEvent(event))
	{
		// Close window
		if (event.type == sf::Event::EventType::Closed)
		{
			_state = STATE_END;
			break;
		}
		// Mouse pressed to choose game mode
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
    			{
				int x = event.mouseButton.x;
				int y = event.mouseButton.y;
				if ( (x >= 330 and x <= 425) and (y >= 155 and y <= 180) )
				{
					_state = STATE_GAME;
				}
				if ( (x >= 345 and x <= 410) and (y >= 252 and y <= 283) )
				{
					_state = STATE_GAME;
					_easy = false;
				}
    			}
		}
		// Select cursor
		if ( event.type == sf::Event::KeyPressed)
		{
			if((event.key.code == sf::Keyboard::Down) or (event.key.code == sf::Keyboard::Up) )
			{
				ctemp = c1;
				c1 = c2;
				c2 = ctemp;
			}
			if(event.key.code == sf::Keyboard::Return)
			{
				if (c1 == sf::Color::Yellow)
					_easy = true;
				else
					_easy = false;
				_state = STATE_GAME;
			}
		}
	}
}

// Logic of menu state
//--------------------------------
void Game::menu_logic()
//--------------------------------
{
	switch ( _state )
	{
		case STATE_GAME: 
			{	
				std::cout << (*this);
				reset_char();
				break;
			}
		default: 
			break;
					
	}
}

/// Render of menu state
//---------------------------------
void Game::menu_render()
//---------------------------------
{
	_screen.put_msg(std::string("Welcome to the game ! "),100, 50, 60, sf::Color::Blue);
	_screen.put_msg(std::string("Easy "),350, 150, 30, c1);
	_screen.put_msg(std::string("Hard"), 353, 250, 30, c2);
	_screen.render();
}

/// Event of play state
//---------------------------------
void Game::play_event()
//---------------------------------
{
	sf::Event event;

	while (_screen.pollEvent(event))
	{
		// Close window
		if (event.type == sf::Event::EventType::Closed)
		{
			_state = STATE_END;
			break;
		}
		// Update cache to change player's direction
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
				case sf::Keyboard::Up: _cache = UP;
							break;
				case sf::Keyboard::Down: _cache = DOWN;
							break;
				case sf::Keyboard::Left: _cache = LEFT;
							break;
				case sf::Keyboard::Right: _cache = RIGHT;
							break;	
				default:
					break;			

			}
		}			
	}
}

// Check if all object is consumed
//-------------------------------
void Game:: play_check()
//-------------------------------
{
	bool b = true;
	for(auto & cell: _grid)
	{
		if ( cell.is_occupied() )
		{
			b = false;
		}
	}
	if (b)
	{
		reset_char();
		reset_map();
		_state = STATE_GAME;
		sf::sleep(sf::milliseconds(1000));
	}
}

// Logic of the play state
//----------------------------------
void Game:: play_logic()
//----------------------------------
{
	// Update direction if cache is not empty
	if (_p.update(_cache, _grid))
	{
		_cache = NONE;
	}
	// Update ghosts
	for(auto & ghost: _ghosts)
	{
		ghost->update(_grid, _p.get_man());
		ghost->move(_grid);
	}
	sf::sleep(sf::milliseconds(125));

	// Check if dead or not
	for(auto & ghost: _ghosts)
	{
		if ( ghost->eat(_p.get_man()) )
		{
			_state = STATE_DEAD;
			_p.kill_man();
			std::cout << (*this);
			std::cout << _p << std::endl;
			break;
		}
	}
	
	// Update position
	if ( _state == STATE_GAME )
	{
		_p.move(_grid);
		for(auto & ghost: _ghosts)
		{
			if ( ghost->eat(_p.get_man()) )
			{
				_state = STATE_DEAD;
				_p.kill_man();
				std::cout << (*this);
				std::cout << _p << std::endl;
 				break;
			}
		}
	}
}

// Event of dead state
//------------------------------
void Game::dead_event()
//------------------------------
{
	sf::Event event;
	while (_screen.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
		{
			_state = STATE_END;
			break;
		}
		if ( event.type == sf::Event::KeyPressed)
		{
			if( (event.key.code == sf::Keyboard::Return) and (_p.is_alive() == false) )
			{
				// Reset
				reset_char();
				reset_map();
				sf::sleep(sf::milliseconds(1000));
				// Reset player
				_p.set_life(3);
				_p.set_score(0);
				// Change state
				_state = STATE_GAME;
				// Print on stdout
				std::cout << (*this);
				break;
			}

		}
	}
}

// Render of dead state
//--------------------------
void Game::dead_render()
//--------------------------
{
	if ( _state == STATE_DEAD)
	{
		_screen.put_msg(std::string("LOST"),400, 320, 24, sf::Color::Yellow);
		if (! _p.is_alive())
		{
			_screen.put_msg(std::string(": type ENTER to play again"), 460, 320, 24, sf::Color::Yellow);
		}
		show();
		sf::sleep(sf::milliseconds(1000));
	}
}

// Check if player life > 0 
//---------------------------
void Game::dead_check()
//---------------------------
{
	if ( _state == STATE_DEAD )
	{	
		if (_p.is_alive())
		{	
			reset_char();
			_state = STATE_GAME;
		}
		else
		{
			_state = STATE_DEAD;
		}
	}
}


// Print map and the characters on screen
//-------------------------
void Game::show()
//-------------------------
{
	_screen.put_msg(std::string("Score: ") + std::to_string(_p.get_score()),60, 320, 24, sf::Color::Yellow);
	if (_p.is_alive())
		_screen.put_msg(std::string("Lives: ") + std::to_string(_p.get_life()),60, 350, 24, sf::Color::Yellow);
	else
		_screen.put_msg(std::string("Lives: ") + std::to_string(0),60, 350, 24, sf::Color::Yellow);
	
	for(auto & cell: _grid)
	{
		cell.draw(_screen);
	}	
	_p.draw(_screen);
	for(auto & ghost: _ghosts)
	{
		ghost->draw(_screen);
	}

	_screen.render();
}

// Overload operator
//----------------------------------------------------------------
std :: ostream& operator<<(std::ostream& out, const Game & g)
//----------------------------------------------------------------
{
	std::string output;
	switch ( g.get_state() )
	{
		case STATE_GAME:
			{
				std::cout << "The game will be running in mode: ";
				if ( g.get_difficulty() )
					std::cout << "easy" << std::endl;
				else
					std::cout << "difficult" << std::endl;
				break;
			}
		case STATE_DEAD:
			{
				std::cout << "You have been eaten !" << std::endl;
				break;
			}
		case STATE_END: 
			{
			{
				std::cout << "The game will be closed. Thanks for playing ! "<< std::endl;
				break;
			}
			}
		default: 
				break;		
	}
	return out << output;
}
