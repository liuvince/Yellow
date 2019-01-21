#pragma once
#include "Ghost.hh"
#include "../src/Screen.hh"

/*
 * Class representing a dumb Ghost
 */

class GhostDumb: public Ghost
{
	public:
		// Constructor
		GhostDumb(Point p, Direction d): Ghost(p, d){};
		// Update direction
		virtual void update(std::vector <Cell> & grid, Pacman man);
		// Draw on screen s
		virtual void draw(Screen & s) const;
};
