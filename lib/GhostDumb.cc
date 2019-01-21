#include "Ghost.hh"
#include "Character.hh"
#include "GhostDumb.hh"
#include <vector>
#include "utility.hh"

// Update direction
//--------------------------------------------------------------
void GhostDumb::update(std::vector <Cell> & grid, Pacman man)
//--------------------------------------------------------------
{
	random_update( grid );
};

// Draw on screen s
//------------------------------------------
void GhostDumb::draw(Screen & s) const
//------------------------------------------
{
	int x = _pos.first;
	int y = _pos.second;
	s.ghostdumb(x, y);
}
