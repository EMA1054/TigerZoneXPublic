//
//  Board.hpp
//  TigerZoneX
//
//  Created by Jacob on 11/5/16.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "TileRelation.hpp"

class Board {
public:
    bool isPlacementValid(int, int, Tile*);
    bool placeTile(int, int, Tile*);
private:
    TileRelation* board[145][145];
    TileRelation* firstTile;
	//Make sure to start at 45,45
};

#endif /* Board_hpp */