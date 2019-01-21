#pragma once

#include <iostream>

// Point: tuple(int, int)
using Point = std::pair<int, int>;

// Direction
enum Direction
{
	NONE,
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum GameStates
{
	STATE_START = 1,
	STATE_GAME = 2,
	STATE_DEAD = 3,
	STATE_END = 4
};
