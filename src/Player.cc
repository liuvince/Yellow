#include <vector>
#include "Player.hh"
#include "SFML/Graphics.hpp"

// Update pacman direction
//----------------------------------------------------------
int Player::update(Direction d, std::vector <Cell> & grid)
//----------------------------------------------------------
{
	int x, y;
	int output = 0;

	x = _man.get_x();
	y = _man.get_y();
	int tab[] = {0, (x-1)*39 + y, (x+1) * 39 +y, x*39 + y+1, x * 39 + y-1};
	if (d != NONE)
	{
		if (grid[tab[d]].is_wall()) 
		{
			output = 0;
		}
		else
		{
			_man.set_direction(d);
			output = 1;
		}
	}
	return output;

}

// Update pacman position
//----------------------------------------------
void Player::move(std::vector <Cell> & grid)
//----------------------------------------------
{
	_man.move(grid);
	int x = _man.get_x();
	int y = _man.get_y();
	if (grid[x*39 + y].is_occupied())
	{
		_score += grid[x*39 + y].get_bonus();
		grid[x*39 + y].del_obj();
		grid[x*39 + y].set_obj(NULL);
	}

}

//----------------------------------------------------------------
std :: ostream& operator<<(std::ostream& out, const Player& p)
//----------------------------------------------------------------
{
	std::string output;
	if ( p.is_alive() ) 
		output = "live(s) left: " + std::to_string( p.get_life() );
	else
		output = "score: " + std::to_string( p.get_score() );
	return out << output;
}
