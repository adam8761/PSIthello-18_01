#pragma once
#include "direction.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class Player class
 * @brief class represents a game engine of the game othello
 */
class Move
{

private:
    int _row;
    int _col;
    std::vector<Direction> _affects ;
public:
    Move(int col, int row, std::vector<Direction> affects);
    int get_row() const;
    int get_col() const;
    bool is_valid(std::vector<std::pair<int, int>> available_moves);
};