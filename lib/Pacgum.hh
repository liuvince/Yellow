#pragma once

#include <iostream>
#include "utility.hh"
#include "GameObject.hh"
#include "../src/Screen.hh"

/*
 * Class representing a pacgum
 */

class Pacgum: public GameObject
{
	public:
		// Constructor
		Pacgum(int bonus): GameObject(bonus){};
		Pacgum(const Pacgum& gb): GameObject(gb.get_bonus()){};
		// Clone in order to make copy
		virtual GameObject * clone() { return new Pacgum(*this); };
		// Draw on Screen s at (x, y) position
		void draw(Screen &s, int x, int y) const { s.pacgum(x, y);};
};
