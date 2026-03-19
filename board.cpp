#include "board.hpp"
#include <vector>
#include <algorithm>

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
    int mid = BOARD_SIZE / 2;
    _cells[mid-1][mid-1].set_piece(PieceType::WHITE);
    _cells[mid-1][mid].set_piece(PieceType::BLACK);
    _cells[mid][mid-1].set_piece(PieceType::BLACK);
    _cells[mid][mid].set_piece(PieceType::WHITE);
}

void Board::print_board(PieceType current_player) const {
    std::vector<std::pair<int,int>> valid = get_valid_moves(current_player);
    std::cout << "  ";
    for (char col = 'A'; col < 'A' + BOARD_SIZE; col++)
        std::cout << col << " ";
    std::cout << "\n";

    for (int row = 0; row < BOARD_SIZE; row++) {
        std::cout << row + 1 << " ";
        for (int col = 0; col < BOARD_SIZE; col++) {
            PieceType curr_piece = _cells[row][col].get_piece();
            char mark;
            if (curr_piece == PieceType::EMPTY && std::find(valid.begin(), valid.end(), std::make_pair(row,col)) != valid.end()) {
                mark = '*';
            } else {
                switch (curr_piece) {
                    case PieceType::EMPTY: mark = '.'; break;
                    case PieceType::BLACK: mark = 'X'; break;
                    case PieceType::WHITE: mark = 'O'; break;
                }
            }
            std::cout << mark << " ";
        }
        std::cout << "\n";
    }
}

void Board::play_game() {
    PieceType current_player = PieceType::BLACK;

    while (true) {
        std::cout << "hi enjoy the game:\n";
        print_board(current_player);

        std::vector<std::pair<int,int>> valid_moves = get_valid_moves(current_player);
        if (valid_moves.empty()) {
            std::cout << "No valid moves for player " << (current_player == PieceType::BLACK ? "X" : "O") << ".\n";

            // to check if the other player is out of moves too
            std::vector<std::pair<int,int>> opponent_moves = get_valid_moves(current_player == PieceType::BLACK ? PieceType::WHITE : PieceType::BLACK);
            if (opponent_moves.empty()) {
                std::cout << "No more moves for both players. Game over!\n";
                int black_score = count_color(PieceType::BLACK);
                int white_score = count_color(PieceType::WHITE);
                std::cout << "Score - X: " << black_score << ", O: " << white_score << "\n";
                return;
            }

            // switches to other player turn
            current_player = (current_player == PieceType::BLACK ? PieceType::WHITE : PieceType::BLACK);
            continue;
        }

        std::string move;
        std::cout << "Player " << (current_player == PieceType::BLACK ? "X" : "O") << " enter move (e.g., D3): ";
        std::cin >> move;

        // TODO: המרת move ל-row,col
        // TODO: בדיקת חוקיות
        // TODO: קריאה ל-place_piece ו-flip_piece

        // החלפת שחקן
        current_player = (current_player == PieceType::BLACK ? PieceType::WHITE : PieceType::BLACK);
    }
}

void Board::flip_piece(int row, int col) {
    PieceType curr = _cells[row][col].get_piece();

    if (curr == PieceType::BLACK)
        _cells[row][col].set_piece(PieceType::WHITE);
    else if (curr == PieceType::WHITE)
        _cells[row][col].set_piece(PieceType::BLACK);
}


std::vector<std::pair<int,int>> Board::get_valid_moves() const { return {}; }
void Board::place_piece(int row, int col, PieceType piece) {}
int Board::count_color(PieceType color) const { return 0; }
int Board::count_score() const { return 0; }