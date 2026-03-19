#pragma once

#include <iostream>
#include <string>

/**
 * @class Player class
 * @brief class represents a game engine of the game othello
 */
class Player
{

private:
    std::string _name;
    PieceType _symbol;

public:
    Player(std::string name, PieceType type);

    std::string get_name() const;
    PieceType get_symbol() const;
    virtual Move get_move() = 0;
};