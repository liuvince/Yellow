#pragma once

#include "utility.hh"
#include "../src/Screen.hh"
#include "Cell.hh"
#include <vector>

/*
 *	This class contains all information about a character
 */
class Character
{
	public:
		// Constructor
		Character(Point p, Direction d):_pos(p), _d(d) {};
		// Draw character on screen S at _pos
		virtual void draw(Screen &s) const = 0;
		// Set position
		void set_direction(Direction d){_d = d;};
		void set_pos(int x, int y);
		void move(std::vector <Cell> &grid);
		// Get position
		int get_x() const {return _pos.first;};
		int get_y() const {return _pos.second;};
		Direction get_dir() const{return _d;};
	protected:
		// Position
		Point _pos;
		// Direction
		Direction _d;
};
