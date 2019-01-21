#pragma once

#include "utility.hh"
#include "GameObject.hh"
#include "../src/Screen.hh"

/* 
 *	This class contains all information about a cell
 *	(e.g accessiblity, objects in there) 
 *	@param _wall (true or false)
 *	@param _obj (cell contents)
 */

class Cell
{
	public:
		// Constructor
		Cell(const Point &p):_p(p), _wall(false), _obj(NULL){};
		Cell(const Point &p, bool wall, GameObject *obj);
		Cell(const Cell &c);
		// Destructor
		~Cell();
		// Draw cell contents on Screen at (x, y) position
		void draw(Screen& s);
		// Return true if current cell represents a wall
		bool is_wall()const{return _wall;};
		// Return true if there is a GameObjet object on current cell
		bool is_occupied()const{return ( _obj != NULL ); };
		// Return GameObject object of current cell
		GameObject * get_obj()const{return _obj;};
		// Deallocate GameObject object
		void del_obj();
		// Setter
		void set_wall(bool w){_wall = w;};
		void set_obj(GameObject * obj){_obj = obj;};
		// Getter
		Point get_point() const{return _p;};
		int get_bonus() const;
	private:
		Point _p;
		// Boolean attribute which represents wall
		bool _wall;
		// GameObject attribute which represents the content of a cell
		GameObject * _obj;
};
