#include "io.hpp"
#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer:\n";
    int x {};
    std::cin >> x;
    return x;
}

void writeAnswer(int x, int y)
{
    std::cout << "The sum is equal to " << x + y << '\n';
}