#include "player.hpp"

Player::Player(std::string name, PieceType type)
{
}

std::string Player::get_name() const
{
    return this->_name;
}

PieceType Player::get_symbol() const
{
    return this->_symbol;
}
