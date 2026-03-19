#pragma once
//#include "board.hpp"
//#include "player_user.hpp"

#include <iostream>
#include <string>
#include <utility>
/**
 * @class Game class
 * @brief class represents a game engine of the game othello
 */
class Game {

    private: 
    static constexpr int PLAYERS_COUNT = 2;
    static constexpr int X_BLACK_PLAYER_INDEX = 0;
    static constexpr int O_WHITE_PLAYER_INDEX = 1;

    static constexpr std::string X_BLACK_PLAYER_NAME = "X";
    static constexpr std::string O_WHITE_PLAYER_NAME = "O";

    //Board _board;
    //Player* _players[PLAYERS_COUNT];
    int* _scores[PLAYERS_COUNT];
    int _curr_player_index;


public:
    void start_game();
    void load_board();
    void take_turn();
    bool is_game_over();

};