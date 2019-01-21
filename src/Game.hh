#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Player.hh"
#include "Cell.hh"
#include "Screen.hh"
#include "Ghost.hh"

/*
 * Main class to controll the game
 */

class Game
{
	public:
		// Constructor
		Game();
		// Destructor
		~Game();
		// Run game
		void run();
		// Getter
		bool get_difficulty() const { return _easy; };
		GameStates get_state() const { return _state; };
		// Overload operator
		friend std :: ostream& operator<<(std::ostream& , const Game &);
	private:
		Player _p;
		Screen _screen;
		Direction _cache;
		std::vector <Cell> _grid;
		std::vector <Ghost *> _ghosts;
		bool _easy;
		int _h, _w;
		GameStates _state;
		// load
		void load_map(std::ifstream &f);
		Direction play(Direction current);
		void load_characters(std::ifstream &f);
		/// GameStates logic
		// MENU
		void menu();
		void menu_event();
		void menu_logic();
		void menu_render();
		// RESET
		void reset_char();
		void reset_map();
		// PLAY
		void play();
		void play_event();
		void play_logic();
		void play_render();
		void play_check();
		// DEAD
		void dead();
		void dead_event();
		void dead_render();
		void dead_check();
		// UTILS
		void end();
		void show();
};
