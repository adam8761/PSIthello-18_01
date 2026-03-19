#pragma once
#include "player.hpp"
#include <iostream>
#include <string>
#include <cctype>

/**
 * @class UserPlayer class
 * @brief class represents a UserPlayer that has the logic of Player class
 */
class UserPlayer : public Player
{

public:
    /**
     * @brief constructor of UserPlayer receiving naem and player color type
     */
    UserPlayer(std::string name, PieceType type) : Player(name, type) {};

    /**
     * @brief function responsible for taking a turn from the user with input and returninig the move
     *
     * @return Move instance formed from the inputed move
     */
    Move get_move() override;
};