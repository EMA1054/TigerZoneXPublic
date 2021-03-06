//
//  Game.hpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Board.hpp"
#include "TileDeck.hpp"
#include "Player.hpp"

class GameInteractor;

class Game {
    friend GameInteractor;
public:
    Game();
    Board* getBoard();
    TileDeck* getDeck();
    Player* getPlayer(int);
    int getTurnIndex();
protected:
    Board* board;
    TileDeck* deck;
    Player* players[2];
    int turnIndex;
};

#endif
