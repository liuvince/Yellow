#include <iostream>
#include <string>
#include "utility.hh"

/// Overload the insertion operator
//-----------------------------------------------------
std::ostream& operator<<(std::ostream& os, Direction d)
//-----------------------------------------------------
{
	switch(d)
    	{
		case UP: os << "UP"; break;
        	case DOWN: os << "DOWN"; break;
        	case RIGHT: os << "RIGHT"; break;
        	case LEFT: os << "LEFT"; break;
        	default: os.setstate(std::ios_base::failbit);
    	}
    	return os;
}

/// Overload the insertion operator
//-----------------------------------------------------
std::ostream& operator<<(std::ostream& os, GameStates gs)
//-----------------------------------------------------
{
    	switch(gs)
    	{
        	case STATE_START: os << "STATE_START"; break;
        	case STATE_GAME: os << "STATE_GAME"; break;
        	case STATE_DEAD: os << "STATE_DEAD"; break;
        	case STATE_END: os << "STATE_END"; break;
        	default: os.setstate(std::ios_base::failbit);
   	}
    	return os;
}
