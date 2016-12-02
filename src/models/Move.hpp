#ifndef Move_hpp
#define Move_hpp

#include "Tile.hpp"
#include <string>

struct Move {
    Move();
	Move(int playerId, int x, int y, Tile* tile, int rotations, bool croc, int tigerZone) :
		playerId(playerId),
		x(x),
		y(y),
		tile(tile),
		rotations(rotations),
		croc(croc),
		tigerZone(tigerZone) {};
    int playerId;
    Tile* tile;
    int rotations;
    int x;
    int y;
    bool croc;
    int tigerZone;
};

#endif
