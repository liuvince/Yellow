#pragma once
#include "Character.hh"
#include "Pacman.hh"
#include "utility.hh"

/*
 * Class representing ghost (abstract)
 */

class Ghost: public Character
{
	public:
		// Constructor
		Ghost(Point p, Direction d): Character(p, d), _cache(NONE){};
		virtual ~Ghost(){};
		// Update direction
		virtual void update(std::vector <Cell> & grid, Pacman man) = 0;
		// Check collision
		bool eat(Pacman man) const {return ( get_x() == man.get_x() ) && ( get_y() == man.get_y() );};
		void random_update(std::vector <Cell> & grid);
		void smart_update(std::vector <Cell> & grid, Pacman p);
	protected:
		Direction _cache;
};
