#include "Character.hh"
#include "utility.hh"
#include "../src/Screen.hh"

/// Given his direction, the character moves
//---------------------------------------------------
void Character::move(std::vector <Cell> &grid)
//---------------------------------------------------
{
	int x, y;
	x = _pos.first;
	y = _pos.second;
	int pos[] = {0,(x-1)*39 + y, (x+1) * 39 +y, x*39 + y+1, x * 39 + y-1};
	switch(_d)
	{
		case UP: 
			if (! grid[pos[UP]].is_wall() ) 
				set_pos(x - 1, y);
			break;
		case DOWN:
			if (! grid[pos[DOWN]].is_wall() ) 
				set_pos(x + 1, y);
			break;
		case RIGHT:
			if (! grid[pos[RIGHT]].is_wall() ) 
				set_pos(x, y + 1);
			break;
		case LEFT:
			if (! grid[pos[LEFT]].is_wall() ) 
				set_pos(x, y - 1);
			break;
		default: break;
	}	
}

/// Setter
//------------------------------------------------
void Character::set_pos(int x, int y)
//------------------------------------------------
{
	_pos.first = x;
	_pos.second = y;
}
