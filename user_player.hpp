#pragma once
#include "player.hpp"
#include <iostream>
#include <string>
#include <cctype>

/**
 * @class Player class
 * @brief class represents a game engine of the game othello
 */
class UserPlayer : public Player
{

public:
    UserPlayer(std::string name, PieceType type);

    Move get_move() override;
};