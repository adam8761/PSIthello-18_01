#include "move.hpp"

Move::Move(int col, int row, std::vector<Direction> affects) : _col(col), _row(row), _affects(affects)
{
}

int Move::get_row() const
{
    return this->_row;
}

int Move::get_col() const
{
    return this->_col;
}

bool Move::is_valid(std::vector<std::pair<int, int>> available_moves)
{
    std::cout << "aaa" << std::endl;
    for (auto available_move : available_moves)
    {
        std::cout << "(" << available_move.first << "," << available_move.second << ")" << std::endl;
        std::cout << "(" << this->_col << "," << this->_row << ")" << std::endl;
        if (available_move.first == this->_col && available_move.second == this->_row)
        {
            return true;
        }
    }
    return false;
}