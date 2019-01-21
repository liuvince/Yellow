#pragma once
#include "Ghost.hh"
#include "../src/Screen.hh"
#include "Pacman.hh"

/*
 * Class representing a smart Ghost
 */

class GhostSmart: public Ghost
{
        public:
		// Constructor
                GhostSmart(Point p, Direction d): Ghost(p, d), _i(40), _j(0){};
		// Virtual methods
                virtual void update(std::vector <Cell> & grid, Pacman man);
                virtual void draw(Screen & s) const;
	private:
		unsigned int _i, _j;
};

