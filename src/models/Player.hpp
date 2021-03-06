#pragma once

#ifndef Player_hpp
#define Player_hpp

#include "Tile.hpp"
#include "TileRelation.hpp"


class Player {
public:
	void incrementScore(int);
	int getScore();
    void setScore(int);
    int getTigerCount();
    void setTigerCount(int);
    void giveTiger();
    int getCrocodileCount();
    void setCrocodileCount(int);
private:
	int tigerCount;
	int crocodileCount;
	int score;
};


#endif /* Player_hpp */
