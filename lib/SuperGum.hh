#pragma once

#include <iostream>
#include "utility.hh"
#include "GameObject.hh"
#include "../src/Screen.hh"

/*
 * Class representing a SuperGum
 */

class Supergum: public GameObject
{
	public:
		// Constructor
		Supergum(int bonus): GameObject(bonus){};
		Supergum(const Supergum & gb): GameObject(gb.get_bonus()){};
		// Clone in order to make copy
		virtual GameObject * clone() { return new Supergum(*this);};
		// Draw on Screen at (x, y) position
		void draw(Screen &s, int x, int y) const { s.supergum(x, y);};
};
