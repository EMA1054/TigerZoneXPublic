//
//  GameInteractor.hpp
//  TigerZoneX
//
//  Created by Chris on 11/27/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef GameInteractor_hpp
#define GameInteractor_hpp

#include <stdio.h>
#include <unordered_map>
#include "Game.hpp"
#include "Tile.hpp"
#include "TileDeck.hpp"
#include "TileLandmark.hpp"
#include "Move.hpp"
#include <queue>

class Interface;

class GameInteractor {
	void visitCoord(std::pair<int, int>, Tile*, int, std::queue< std::pair<int, int> >, bool[][153], std::vector<Move>);
protected:
    Game* game;
//private:
    // Check if a trail is complete
    bool isComplete(TileTrail*);
    // Check if a lake is complete
    bool isComplete(TileLake*, std::unordered_map<TileLandmark*, bool>&);
    // Check if a den is complete
    bool isComplete(TileDen*);
    void appendTrails(TileTrail*, TileTrail*);
    void appendLakes(TileLake*, TileLake*, Position);
    bool hasOwner(TileTrail*);
    bool hasOwner(TileLake*, std::unordered_map<TileLake*,bool>&);
    bool hasOwner(TileDen*);
    Player* getOwner(TileTrail*);
    Player* getOwner(TileLake*, std::unordered_map<TileLake*,bool>&, Player*);
    Player* getOwner(TileDen*);
//    bool placeTiger(TileLandmark*);
//    bool placeTigerOnSkip(TileLandmark*);
//    bool placeCrocodile(TileLandmark*);
    // Give any tigers on the landmark back to players
    void returnTigers(TileLandmark*);
    void returnTigers(TileTrail*);
    void returnTigers(TileLake*, std::unordered_map<TileLake*,bool>&);
    void returnTigers(TileDen*);
    int getCrocodileCount(TileTrail*);
    int getCrocodileCount(TileLake*, std::unordered_map<TileLake*,bool>&, int);
    int getCrocodileCount(TileDen*);
    Move* lastMove;
    std::vector<Interface*> views;
public:
    void attachInterface(Interface*);
    void notifyInterfaces();
    
    // Initialize game, setup deck, setup board
    GameInteractor();
	GameInteractor(std::string deckString);
    
    //Default game
    // Sets up a new game with the default values
    void setupGame();
    // Define tiles, shuffle them, and add tile type S at the top
    void setupTileDeck();
    // Set first tile, at (76,76), to tile at top of deck
    void setupBoard();
    // Setup 2-player game and alot tigers & crocodiles
    void setupPlayers();
    
    
    // Sets up a game with specified starting values
    void setupGame(Tile* startTile, int startX, int startY, std::vector<Tile*> deckTiles);
    // Define tile deck from vector
    void setupTileDeck(std::vector<Tile*> deckTiles);
    // Set first tile at (startX, startY) to startTile
    void setupBoard(Tile* startTile, int startX, int startY);
    
    Game& getGame();
    void setGame(Game&);
    
    //TileDeck
    // Shuffle the deck
	void shuffleDeck();
    // Create a tile from Dave's defined tile sequences
	static Tile* createTileFromSequence(std::string);
    // Create a tile from alphabetic template
    static Tile* createTileFromTemplate(char);
    // Create a vector of all the game tiles
    static std::vector<Tile*> defineTiles();
    // Return the top tile from the deck, and remove it
    Tile* drawTile();
    
//    void setupTileDeck()

    //Tile
    // Rotate a tile clockwise once
    static void rotateTile(Tile*);
    // Rotate a tile clockwise n times
    static void rotateTile(Tile*, int);
    
    //Board
    // Check if tile placement is valid
    bool isPlacementValid(int, int, Tile*);
    // Implement landmarks from tile placement
    void placeLandmarks(int, int, Tile*);
    // Create a tile relation at coordinates
    bool placeTile(int, int, Tile*);
    
    //Landmarks
    // Check if landmark is complete (calls overloaded isComplete for specific landmark type)
    bool isComplete(TileLandmark*);
    static TileLandmark* createTileLandmark(LandmarkType);
    bool append(TileLandmark*, TileLandmark*, Position);
    // Returns whether or not a landmark has an owner based on tigers
    bool hasOwner(TileLandmark*);
    // Return owner of landmark based on tigers. NULL if two owners or none
    Player* getOwner(TileLandmark*);
    // Get the unique completed landmarks at coordinates
    std::unordered_map<TileLandmark*,bool> getCompleteLandmarks(int x, int y);
    int getCrocodileCount(TileLandmark*);
    
    //Player
    
    // For every landmark on the tile, return the landmark's tigers to the players if the landmark is completed
    void returnTigers(int x, int y);
    
    //Game
    // Place the next tile at the given xy-coordinate and place a tiger or croc in the specified zone
    bool playTurn(int x, int y, int rotations = 0, bool tiger = false, bool croc = false, int zone = 0);
    Move getLastMove();

	//AI
	std::vector<Move> listPossibleMoves();
};

#endif /* GameInteractor_hpp */
