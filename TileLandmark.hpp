//
//  TileLandmark.hpp
//  TigerZoneX
//
//  Created by Chris on 11/19/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef TileLandmark_hpp
#define TileLandmark_hpp

#include <stdio.h>
#include <vector>
#include "Player.hpp"
#include "Tile.hpp"

// Forward declarations since we can't two-way include
class Landmark;
class Trail;
class Lake;
class Den;

// TODO: Consider adding quadrants to this
class TileLandmark {
    friend class Landmark;
private:
    Player* tigerOwnedBy;
    // The parent landmark, containing all tile landmarks
    Landmark* landmark;
};

class TileTrail : public TileLandmark {
    friend class Trail;
private:
    TileTrail* nextTrail;
    TileTrail* prevTrail;
    bool trailEnds;
    bool hasCrocodile;
};

class TileLake : public TileLandmark {
    friend class Lake;
private:
    TileLake* nLake;
    TileLake* eLake;
    TileLake* sLake;
    TileLake* wLake;
    bool lakeEnds;
    bool hasCrocodile;
};

class TileDen : public TileLandmark {
    friend class Den;
private:
    std::vector<Tile*> surroundingTiles;
};

#endif /* TileLandmark_hpp */
