#pragma once
#include "piece_type.hpp"

/**
 * @class Cell
 * @brief represents one cell on the board.
 */
class Cell {
private:
    PieceType _state;

public:
    /**
     * @brief default constructor. sets the cell as empty in the beginning.
     */
    Cell();

    /**
     * @brief checks if the cell is empty or not.
     * 
     * @return true if it's empty, false othwerwise
     */
    bool is_empty() const;

    /**
     * @brief returns the piece type (empty, black, white)
     * 
     * @return the piece type
     */
    PieceType get_piece() const;

    /**
     * @brief changes the type of the piece (empty, black, white)
     * 
     * @param piece given piece type to change
     */
    void set_piece(PieceType piece);
};