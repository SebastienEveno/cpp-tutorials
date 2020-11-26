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

int getInputFromUser(int count)
{
    while (true)
    {
        std::cout << "Guess #" << count << ": ";
        int x{};
        std::cin >> x;
        
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767,'\n'); // and remove the bad input
        }
        else // else our extraction succeeded
        {
            std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed
            return x; // so return the value we extracted
        }
    }
}

bool playHiLo(int guesses, int randomNumber)
{
    for (int count {1}; count <= guesses; ++count)
    {
        int x { getInputFromUser(count) };

        if (x == randomNumber)
            return true;
        else if (x > randomNumber)
            std::cout << "Your guess is too high" << '\n';
        else
            std::cout << "Your guess is too low" << '\n';
    }

    return false;

}

bool playAgain()
{
    while (true)
    {
        char ch {};
        std::cout << "Would you like to play again (y/n)?";
        std::cin >> ch;
        switch (ch)
        {
            case 'y':
                return true;
            case 'n':
                return false;
        }
    }
}

int main()
{
    do 
    {
        std::cout << "Let's play a game.  I'm thinking of a number (between 1 and 100).  You have 7 tries to guess what it is." << '\n';
        const int randomNumber { getRandomNumber(Constants::minRangeValue, Constants::maxRangeValue) };
        bool won = playHiLo(Constants::maximumNumberOfTries, randomNumber);
        if (won)
            std::cout << "Correct! You win!" << '\n';
        else
            std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";

    } while (playAgain());

    std::cout << "Thank you for playing." << '\n';

    return 0;
}