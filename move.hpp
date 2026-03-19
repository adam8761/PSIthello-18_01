#pragma once
#include "direction.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class Move class
 * @brief class represents a Move action
 */
class Move
{

private:
    int _row;
    int _col;
    std::vector<Direction> _affects;

public:
    static constexpr char INVALID_MOVE_MESSAGE[] = "Invalid move!\nPress Enter...\n";
    /**
     * @brief constructor of Move receiving cordinates and directions it affects
     */
    Move(int row, int col, std::vector<Direction> affects = std::vector<Direction>()) : _row(row), _col(col), _affects(affects) {};

    /**
     * @brief getter of field _row
     */
    int get_row() const;

    /**
     * @brief getter of field _col
     */
    int get_col() const;

    /**
     * @brief function checks if move is valid based on given avialable moves
     */
    bool is_valid(std::vector<std::pair<int, int>> available_moves);
};