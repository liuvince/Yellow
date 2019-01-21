#pragma once

#include <vector>
#include "utility.hh"
#include "Character.hh"
#include "../src/Screen.hh"

/*
 * Class representing Pacman
 */

class Pacman: public Character
{
	public:
		// Constructor
		Pacman(Point p, Direction d): Character(p, d){};
		// draw on screen s at pos position
		virtual void draw(Screen & s) const{ s.pacman(_pos.first, _pos.second);};

};
