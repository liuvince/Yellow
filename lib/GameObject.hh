#pragma once

#include <iostream>
#include "utility.hh"
#include "../src/Screen.hh"

/*
 *  Class representing GameObject like PacMan, ghost
 */

class GameObject
{
	public:
		// Constructor
		GameObject(): _bonus(0){};
		GameObject(int bonus): _bonus(bonus){};
		GameObject(const GameObject&g):_bonus(g.get_bonus()) {};
		virtual GameObject * clone() = 0;
		// Destructor
		virtual ~GameObject(){};
		// Getter
		int get_bonus() const{return _bonus;};
		// draw methods
		virtual void draw(Screen & s, int x, int y) const = 0;
	private:
		int _bonus;
};
