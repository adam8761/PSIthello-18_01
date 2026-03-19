#pragma once
#include "piece_type.hpp"
#include "cell.hpp"
#include <vector>
#include <iostream>

/**
 * @class Board
 * @brief the 8x8 othello board and its functions
 */
class Board {
private:
    static constexpr int BOARD_SIZE = 8;
    Cell _cells[BOARD_SIZE][BOARD_SIZE];

public:
    /**
     * @brief default constructor
     */
    Board();

    /**
     * @brief initializes the board itself, including for example the size 8x8
     */
    void init_board();

    /**
     * @brief prints the board on the terminal
     * 
     * @param current_player the current player. its mainly for the player to see on the board
     * the (*), so he knows what are his valid moves in his turn.
     */
    void print_board(PieceType current_player) const;

    /**
     * @brief the function that runs the flow of the game
     */
    void play_game();

    // to add as i continue

    /**
     * @brief flips the piece on the board.
     * from black to white or white to black. 
     * from the row and column you know the coordinate of the piece.
     * 
     * @param row row of the piece we want to flip
     * @param column column of the piece we want to flip
     */
    void flip_piece(int row, int col);

    /**
     * @brief gets valid moves. returns a std::pair that saves a location on the board
     */
    std::vector<std::pair<int,int>> get_valid_moves() const;

    /**
     * @brief places piece on the board.
     * 
     * @param row row of the piece we want to place
     * @param column column of the piece we want to place
     * @param piece the type of the piece (empty, black, white)
     */
    void place_piece(int row, int col, PieceType piece);

    /**
     * @brief counts the number of the same color piece on board.
     * for example all the black pieces.
     * 
     * @param color given color of piece
     * 
     * @return the total number of the pieces on board in this color
     */
    int count_color(PieceType color) const;

    /**
     * @brief counts the current score according to the board
     * 
     * @return the score
     */
    int count_score() const;
};