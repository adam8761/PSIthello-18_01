#pragma once
#include "piece_type.hpp"
#include "move.hpp"
#include <iostream>
#include <string>

/**
 * @class Player class
 * @brief abstract class represents a basic player in the othello game
 */
class Player
{

private:
    std::string _name;
    PieceType _symbol;

public:
    /**
     * @brief constructor of Player receiving name and player color type
     */
    Player(std::string name, PieceType type) : _name(name), _symbol(type) {};

    /**
     * @brief getter for _name field
     * @return _name value
     */
    std::string get_name() const;

    /**
     * @brief getter for _symbol field
     * @return _symbol value
     */
    PieceType get_symbol() const;

    /**
     * @brief virtual function of generating a move from the user, for each use to have its own way of generating a move
     */
    virtual Move get_move() = 0;
};