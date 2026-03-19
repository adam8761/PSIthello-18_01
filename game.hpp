#pragma once
#include "board.hpp"
#include "user_player.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

/**
 * @class Game class
 * @brief class represents a game engine of the game othello
 */
class Game
{
protected:
    static constexpr int PLAYERS_COUNT = 2;
    static constexpr int X_BLACK_PLAYER_INDEX = 0;
    static constexpr int O_WHITE_PLAYER_INDEX = 1;

    static constexpr char X_BLACK_PLAYER_NAME[] = "X";
    static constexpr char O_WHITE_PLAYER_NAME[] = "O";

private:
    Board _board;
    Player *_players[PLAYERS_COUNT];
    int _scores[PLAYERS_COUNT];
    int _curr_player_index;

public:
    /**
     * @brief function initializes a new game and starts its flow run
     */
    void start_game();

    /**
     * @brief function loads the console screen with board and relevant prints
     */
    void load_board();

    /**
     * @brief function is responsible for turn taking and commiting on screen
     */
    void take_turn();

    /**
     * @brief function checks if game is at deadend and over, returns a formal boolean
     *
     * @return true-game over, false-game not over
     */
    bool is_game_over();
};