#include "cell.hpp"

Cell::Cell() : _state(PieceType::EMPTY) {}

bool Cell::is_empty() const {
    return _state == PieceType::EMPTY;
}

PieceType Cell::get_piece() const {
    return _state;
}

void Cell::set_piece(PieceType piece) {
    _state = piece;
}