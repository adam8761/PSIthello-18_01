#include "board.hpp"
#include <iostream>

int main() {
    Board board;
    std::cout << "Othello Board:\n";
    board.print_board();

    return 0;
}