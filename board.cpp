#include "board.hpp"
#include <vector>
#include <algorithm>

Board::Board() {
    init_board();
}

void Board::init_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
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

void Board::print_board(Player* current_player) const {
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


void Board::flip_piece(int row, int col) {
    PieceType curr = _cells[row][col].get_piece();

    if (curr == PieceType::BLACK)
        _cells[row][col].set_piece(PieceType::WHITE);
    else if (curr == PieceType::WHITE)
        _cells[row][col].set_piece(PieceType::BLACK);
}

std::vector<std::pair<int,int>> Board::get_valid_moves(Player* player) const {
    std::vector<std::pair<int,int>> moves;
    PieceType opponent = (player->get_symbol() == PieceType::BLACK ? PieceType::WHITE : PieceType::BLACK);
    int directions[8][2] = {{-1,-1},{-1,0},{-1,1}, {0,-1},{0,1}, {1,-1},{1,0},{1,1}};

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (_cells[row][col].get_piece() != PieceType::EMPTY)
                continue;

            bool valid = false;
            for (auto &dir : directions) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];

                bool found_opponent = false;
                while (new_row >= 0 && new_row < BOARD_SIZE && new_col >= 0 && new_col < BOARD_SIZE) {
                    PieceType piece = _cells[new_row][new_col].get_piece();

                    if (piece == opponent) {
                        found_opponent = true;
                    }
                    else if (piece == player->get_symbol()) {
                        if (found_opponent)
                            valid = true;
                        break;
                    }
                    else {
                        break;
                    }
                    new_row += dir[0];
                    new_col += dir[1];
                }
                if (valid)
                    break;
            }
            if (valid)
                moves.push_back(std::pair<int,int>(row,col));
        }
    }
    return moves;
}

void Board::place_piece(int row, int col, PieceType piece)
{
    _cells[row][col].set_piece(piece);
    PieceType opponent = (piece == PieceType::BLACK) ? PieceType::WHITE : PieceType::BLACK;
    int directions[8][2] = {{-1,-1},{-1,0},{-1,1}, {0,-1},{0,1}, {1,-1},{1,0},{1,1}};

    for (const auto& dir : directions)
    {
        int new_row = row + dir[0];
        int new_col = col + dir[1];

        std::vector<std::pair<int,int>> to_flip;
        while (new_row >= 0 && new_row < BOARD_SIZE && new_col >= 0 && new_col < BOARD_SIZE &&
               _cells[new_row][new_col].get_piece() == opponent)
        {
            to_flip.push_back({new_row, new_col});
            new_row += dir[0];
            new_col += dir[1];
        }

        if (new_row >= 0 && new_row < BOARD_SIZE && new_col >= 0 && new_col < BOARD_SIZE &&
            _cells[new_row][new_col].get_piece() == piece)
        {
            for (auto& pos : to_flip)
            {
                _cells[pos.first][pos.second].set_piece(piece);
            }
        }
    }
}

int Board::count_color(PieceType color) const {
    int count = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (_cells[row][col].get_piece() == color)
                count++;
        }
    }
    return count;
}

