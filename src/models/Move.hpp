#ifndef Move_hpp
#define Move_hpp

#include "Tile.hpp"
#include <string>

struct Move {
	Move() {};
    Move(int playerId, int x, int y, Tile* tile, int rotations, bool croc, int tigerZone);
    int playerId;
    Tile* tile;
    int rotations;
    int x;
    int y;
    bool croc;
    int tigerZone;
	bool forfeit;
	bool pass;
};

#endif
