#include "board.hpp"

Board::Board() {
    init_board();
}

void Board::init_board() {
    for (int row = 0; row < Board::BOARD_SIZE; row++) {
        for (int col = 0; col < Board::BOARD_SIZE; col++) {
            _cells[row][col].set_piece(PieceType::EMPTY);
        }
    }

    // 4 cells are in the beginning
    _cells[3][3].set_piece(PieceType::WHITE);
    _cells[3][4].set_piece(PieceType::BLACK);
    _cells[4][3].set_piece(PieceType::BLACK);
    _cells[4][4].set_piece(PieceType::WHITE);
}

void Board::print_board() const {
    std::cout << "  ";
    for (int col = 0; col < Board::BOARD_SIZE; col++)
        std::cout << col << " ";
    std::cout << "\n";

    for (int row = 0; row < Board::BOARD_SIZE; row++) {
        std::cout << row << " ";
        for (int col = 0; col < 8; col++) {
            PieceType p = _cells[row][col].get_piece();
            char ch = (p == PieceType::EMPTY) ? '.' : (p == PieceType::BLACK ? 'B' : 'W');
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
}

// placeholders
void Board::flip_piece(int row, int col) {}
std::vector<std::pair<int,int>> Board::get_valid_moves() const { return {}; }
void Board::place_piece(int row, int col, PieceType piece) {}
int Board::count_color(PieceType color) const { return 0; }
int Board::count_score() const { return 0; }