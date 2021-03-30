#include <iostream>
#include "creature.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result
    
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;
    
    Player player{ playerName };
    std::cout << "Welcome, " << player.getName() << '\n';

    while(!player.isDead() && !player.hasWon())
    {
        player.fightMonster();
    }
    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You won the game with " << player.getGold() << " gold!\n";
    }

	return 0;
}

