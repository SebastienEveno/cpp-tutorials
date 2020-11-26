#include <iostream>
#include <iterator> // for std::size

int main() 
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int numberOfElements {static_cast<int>(std::size(array))};
    std::cout << numberOfElements << '\n';

    // Ask the user a number between 1 and 9
    int x {};
    do 
    {
        std::cout << "Please enter an integer between 1 and 9 (inclusive): " << '\n';
        std::cin >> x;
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags
        std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
    } while ((x < 1) || (x > 9));

    // Print the array
    for (int i{ 0 }; i < numberOfElements; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    for (int j{ 0 }; j < numberOfElements; ++j)
    {
        if (array[j] == x)
            std::cout << "Corresponding index: " << j << '\n';
    }
    
    return 0;
}