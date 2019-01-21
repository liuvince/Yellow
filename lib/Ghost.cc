#include "Ghost.hh"
#include "Character.hh"
#include <vector>
#include "utility.hh"
#include <unordered_map> 

// Update direction
//--------------------------------------------------------------
void Ghost::random_update(std::vector <Cell> & grid)
//--------------------------------------------------------------
{
	std::vector <Direction> possible_direction;
	int x, y;
	x = _pos.first;
	y = _pos.second;
	int alea;
	Direction current = _d;
	
	int tab[] = {0,(x-1)*39 + y, (x+1) * 39 +y, x*39 + y+1, x * 39 + y-1};

	if ( current != UP and !grid[tab[UP]].is_wall() )
	{
		possible_direction.push_back(UP);
	}
	if ( current != DOWN and !grid[tab[DOWN]].is_wall() )
	{
		possible_direction.push_back(DOWN);
	}
	if ( current != RIGHT and !grid[tab[RIGHT]].is_wall() )
	{
		possible_direction.push_back(RIGHT);
	}
	if ( current != LEFT and !grid[tab[LEFT]].is_wall() )
	{
		possible_direction.push_back(LEFT);
	}

	if ( (grid[tab[current]].is_wall()) ) 
	{
		if ( possible_direction.size() == 1 )
		{
			set_direction(possible_direction[0]);
		}
		else
		{
			//alea = rand() % possible_direction.size();
			do
			{
				alea = rand() % possible_direction.size();
			} while (possible_direction[alea] == _cache);
			set_direction(possible_direction[alea]);
		}
	}
	else
	{
		alea = rand() % 6; // Probability of changing direction
		if (alea == 0)
		{
			alea = rand() % possible_direction.size();
			if (possible_direction[alea] != _cache)
			{
				set_direction(possible_direction[alea]);
			}
		}
	}
	Direction tabd[] = {NONE, DOWN, UP, LEFT, RIGHT};
	_cache = tabd[current];

};

// Update direction
//--------------------------------------------------------------
void Ghost::smart_update(std::vector <Cell> & grid, Pacman man)
//--------------------------------------------------------------
{
	std::vector <Direction> possible_direction;
	int x, y;
	x = _pos.first;
	y = _pos.second;
	int tab[] = {0,(x-1)*39 + y, (x+1) * 39 +y, x*39 + y+1, x * 39 + y-1};
	//Direction current = _d;
	std::unordered_map<Direction, int> umap; 
	int min = 10000;
	Direction dir_min = _d;
	if ( !grid[tab[UP]].is_wall() )
	{
		umap[UP] = ((x-1) - man.get_x()) * ((x-1) - man.get_x())  + (y - man.get_y()) * (y - man.get_y());
		min = umap[UP];
		dir_min = UP;
	}
	if ( !grid[tab[DOWN]].is_wall() )
	{
		umap[DOWN] = ((x+1) - man.get_x()) * ((x+1) - man.get_x()) + (y- man.get_y()) * (y- man.get_y());
		min = umap[DOWN];
		dir_min = DOWN;
	}
	if ( !grid[tab[RIGHT]].is_wall() )
	{
		umap[RIGHT] = (x - man.get_x()) * (x - man.get_x()) + (y+1- man.get_y()) * (y+1- man.get_y());
		min = umap[RIGHT];
		dir_min = RIGHT;
	}
	if ( !grid[tab[LEFT]].is_wall() )
	{
		umap[LEFT] = (x - man.get_x()) * (x - man.get_x())+ (y-1- man.get_y()) * (y-1- man.get_y()) ;
		min = umap[LEFT];
		dir_min = LEFT;
	}


	for (auto &x : umap)
	{ 
      		if ( x.second <= min )
		{
			dir_min = x.first;
			min = x.second;
		}
	}
	set_direction(dir_min);

}

