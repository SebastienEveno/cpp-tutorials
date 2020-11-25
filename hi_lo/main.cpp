#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

#include "constants.h"

namespace Random {
    // Initialize our mersenne twister with a random seed based on the clock
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int getRandomNumber(int min, int max)
{
    // Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution<int> randomNumber{ min, max };
    return randomNumber(Random::mersenne);
}

void playSingleGameHiLo()
{
    std::cout << "Let's play a game.  I'm thinking of a number (between 1 and 100).  You have 7 tries to guess what it is." << '\n';
    const int randomNumber { getRandomNumber(Constants::minRangeValue, Constants::maxRangeValue) };
    int count {1};

    while (count <= Constants::maximumNumberOfTries)
    {
        std::cout << "Guess #" << count << ": ";
        int x {};
        std::cin >> x;
        // std::cout << '\n';
        if (x == randomNumber)
        {
            std::cout << "Correct! You win!" << '\n';
            break;
        } 
        else if (x > randomNumber)
        {
            std::cout << "Your guess is too high" << '\n';
        } 
        else
        {
            std::cout << "Your guess is too low" << '\n';
        }
        ++count;
    }
    
    if (count > Constants::maximumNumberOfTries)
        std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
}

int main()
{
    char ch = 'y';
    do 
    {
        playSingleGameHiLo();
        do
        {
            std::cout << "Would you like to play again (y/n)?";
            std::cin >> ch;
        } while ((ch == 'y') || (ch == 'n'));

    } while (ch == 'y');

    std::cout << "Thank you for playing." << '\n';

    return 0;
}