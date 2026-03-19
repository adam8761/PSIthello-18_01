#include "game.hpp"

void Game::start_game()
{

    this->_players[X_BLACK_PLAYER_INDEX] = new UserPlayer(X_BLACK_PLAYER_NAME, PieceType::BLACK);
    this->_players[O_WHITE_PLAYER_INDEX] = new UserPlayer(O_WHITE_PLAYER_NAME, PieceType::WHITE);

    this->_board.init_board();
    this->_scores[X_BLACK_PLAYER_INDEX] = 2;
    this->_scores[O_WHITE_PLAYER_INDEX] = 2;

    this->_curr_player_index = X_BLACK_PLAYER_INDEX; // black/x starts

    this->load_board();
    while (!this->is_game_over())
    {
        this->take_turn();
        this->load_board();
    }
}

void Game::load_board()
{
    system("cls");
    this->_board.print_board(this->_players[this->_curr_player_index]);
    std::cout << "Player " << this->_players[this->_curr_player_index]->get_name() << " enter move (e.g., D3):";
}

void Game::take_turn()
{
    std::vector<std::pair<int, int>> available_moves = this->_board.get_valid_moves(this->_players[this->_curr_player_index]);
    // std::vector<std::pair<int, int>> available_moves;

    Move move = this->_players[this->_curr_player_index]->get_move();

    while (!move.is_valid(available_moves))
    {
        std::cin.clear();
        std::string s;
        std::getline(std::cin, s);
        std::getline(std::cin, s);
        std::cin.clear();

        this->load_board();
        move = this->_players[this->_curr_player_index]->get_move();
    }
    this->_board.place_piece(move.get_row(), move.get_col(), this->_players[this->_curr_player_index]->get_symbol());

    this->_curr_player_index = !this->_curr_player_index;
}

bool Game::is_game_over()
{
    if (this->_board.get_valid_moves(this->_players[this->_curr_player_index]).empty())
    {
        std::cout << "Game Over!" << std::endl;
        std::cout << "X: " << this->_board.count_color(PieceType::BLACK) << " O: " << this->_board.count_color(PieceType::BLACK);

    }
    return false;
}
