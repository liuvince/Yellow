#pragma once

#include <iostream>
#include <vector>
#include "Pacman.hh"
#include "utility.hh"
#include "Screen.hh"
#include "Cell.hh"

/* 
 * Class representing a player
 */
class Player
{
	public:
		// Constructor
		Player(): _score(0), _life(3), _man(Point(0,0), UP) {};
		Player(Point p):_score(0), _life(3), _man(p, UP) {};
		void draw(Screen &s){_man.draw(s);};
		// update direction of the player
		int update(Direction d, std::vector <Cell> & grid);		
		void move(std::vector <Cell> & grid);
		// Setter
		void set_pos(int x, int y){_man.set_pos(x, y);};
		void set_direction(Direction d){_man.set_direction(d);};
		void set_life(int l){_life = l;};
		void set_score(int s){_score = s;};
		// Getter
		Pacman get_man() const {return _man;};
		Direction get_direction() const{return _man.get_dir();};
		int get_score() const{return _score;};
		int get_life() const{ return _life;};
		// Function about player's life
		void kill_man() { _life --;};
		int is_alive() const { return (_life >= 0); }; 
		// Overload operator
		friend std :: ostream& operator<<(std::ostream& , const Player &);
	private:
		unsigned long _score;
		int _life;
		Pacman _man;		
};
