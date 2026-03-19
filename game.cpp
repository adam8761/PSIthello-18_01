#include "game.hpp"

void Game::start_game()
{
    
    //this->_players[X_BLACK_PLAYER_INDEX] = new UserPlayer(X_BLACK_PLAYER_NAME, PieceType::BLACK);
    //this->_players[O_WHITE_PLAYER_INDEX] = new UserPlayer(O_WHITE_PLAYER_NAME, PieceType::WHITE);

    //this->_board->init_board();

    this->_curr_player_index = 0;
    while (!this->is_game_over()){
        this->take_turn();
        this->load_board();
    }
}

void Game::load_board()
{
    system("cls");
    // this->_board->print_board();
    // std::cout<< "Player "<<this->_players[this->_curr_player_index]->get_name() <<"enter move (e.g., D3):";
}

void Game::take_turn()
{
    // Move move = this->_players[this->_curr_player_index]->get_move();
    // while (!move->is_valid()){
    //     move = this->_players[this->_curr_player_index]->get_move();
    // }
    // this->_board->place_piece(std::pair<move->get_col(),move->get_row());

    this->_curr_player_index = !this->_curr_player_index;
}

bool Game::is_game_over()
{
    // if (this->_board->get_valid_moves())
    return false;
}
