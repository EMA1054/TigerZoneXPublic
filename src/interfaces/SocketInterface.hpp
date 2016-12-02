//
//  SocketInterface.hpp
//  TigerZoneX
//
//  Created by Chris on 11/30/16.
//  Copyright © 2016 Chris Anderson. All rights reserved.
//

#ifndef SocketInterface_hpp
#define SocketInterface_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <regex>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "GameInteractor.hpp"
#include <unordered_map>

using boost::asio::ip::tcp;

using boost::asio::ip::tcp;

class SocketInterface {
private:
    boost::system::error_code error;
    tcp::socket* socket;
    std::string IP;
    std::string PORT;
    std::string TOURNAMENT_PASSWORD;
    std::string TEAM_USERNAME;
    std::string TEAM_PASSWORD;
    GameInteractor a;
    GameInteractor b;
    std::unordered_map<std::string, GameInteractor> activeGames;
    
    int numOfRounds;
    int numOfTiles; //Not including starting tile
public:
    SocketInterface(std::string server, std::string port, std::string tournamentPassword, std::string teamUsername, std::string teamPassword);
    std::string readLineFromSocket();
    void writeLineToSocket(std::string message);
    
    boost::system::system_error getErrorCode();
    std::smatch regexSearchNextMessage(const char*);
    bool regexMatchNextMessage(const char*);
    void connect();
    
    void authenticate();
    
    void receiveChallenge();
    
    void beginRound();
    
    void beginMatch();
    
    void receiveMove();
    
    void sendMove();
    
    void endMatch();
    
    void playTournament();
    
};

#endif /* SocketInterface_hpp */
