#include "user_player.hpp"

Move UserPlayer::get_move()
{
    std::string move_input = "";
    std::cin >> move_input;
    if (move_input.length() != 2)
    {
        return Move(-1, -1, std::vector<Direction>());
    }
    else if (!std::isalpha(move_input[0]) || !std::isdigit(move_input[1]))
    {
        return Move(-1, -1, std::vector<Direction>());
    }
    else
    {
        return Move(move_input[1] - 49, move_input[0] - 65, std::vector<Direction>());
    }
}
