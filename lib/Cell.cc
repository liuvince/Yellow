#include "Cell.hh"
#include "../src/Screen.hh"

/// Constructor
//-------------------------------------------------------------
Cell::Cell(const Point &p, bool wall, GameObject * obj): _p(p), _wall(wall), _obj(obj)
//-------------------------------------------------------------
{
	if (_wall)
	{
		_obj = NULL;
	}
}


/// Copy constructor
//-------------------------------------------------------------
Cell::Cell(const Cell& c): _p(c.get_point()), _wall(c.is_wall())
//-------------------------------------------------------------
{
	GameObject * G = c.get_obj();
	if (G)
	{
		_obj = G->clone();
	}
	else
	{
		_obj = G;
	}
}

/// Destructor
//-------------------------------------------------------------
Cell::~Cell()
//-------------------------------------------------------------
{
	del_obj();
}

/// Deallocate GameObject object
//-------------------------------------------------------------
void Cell::del_obj()
//-------------------------------------------------------------
{
	if (is_occupied())
	{
		delete _obj;
	}
}

/// Draw cell contents on Screen s at (x,y) position
//-------------------------------------------------------------
void Cell::draw(Screen & s)
//-------------------------------------------------------------
{
	int x = _p.first;
	int y = _p.second;
	// if wall at (x,y) position
	if (_wall)
	{
		s.wall(x, y);
	}
	else
	{
		// if game object at (x,y) position
		if(is_occupied())
		{
			_obj->draw(s, x, y);
		}
	}
}

/// Get bonus 
//-------------------------------------------------------------
int Cell::get_bonus() const
//-------------------------------------------------------------
{
	if (is_occupied())
	{
		return _obj->get_bonus();
	}
	return 0;
}

