#include "deck.hpp"
#include "blackjack.hpp"

int main()
{
    Blackjack game{};
    if (game.playBlackjack())
        std::cout << "You won!\n";
    else
        std::cout << "Dealer won.\n";
    
    return 0;
}