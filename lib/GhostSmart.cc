#include "Ghost.hh"
#include "Character.hh"
#include "GhostSmart.hh"
#include <vector>
#include "utility.hh"
#include <unordered_map> 
#include "Pacman.hh"

// Update direction
//---------------------------------------------------------------------
void GhostSmart::update(std::vector <Cell> & grid, Pacman man)
//---------------------------------------------------------------------
{
	--_i;
	if (_i == 0)
	{
		if (_j == 0)
		{
			_i = 10;
			_j = 1;
		}
		else
		{
			_i = 40;
			_j = 0;
		}
	}
	if (_j == 0)
	{
		random_update( grid );
	}
	else
	{
		smart_update( grid , man);
	}
}

// Draw on screen
//---------------------------------------------
void GhostSmart::draw(Screen & s) const
//---------------------------------------------
{
	int x = _pos.first;
	int y = _pos.second;
	s.ghostsmart(x, y);
}
