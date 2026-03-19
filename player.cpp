#include "player.hpp"

std::string Player::get_name() const
{
    return this->_name;
}

PieceType Player::get_symbol() const
{
    return this->_symbol;
}
