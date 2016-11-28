//
//  Game.hpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#include "Board.hpp"
#include "TileDeck.hpp"
#include "Player.hpp"

class GameInteractor;

class Game {
    friend GameInteractor;
private:
    Board* board;
    TileDeck* deck;
    Player* players[2];
    int turnIndex;
};