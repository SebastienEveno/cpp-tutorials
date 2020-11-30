#include <iostream>
#include <algorithm> // for std::sort
#include <cstddef> // std::size_t
#include <limits> // std::numeric_limits
#include <string>

int main () 
{
    std::cout << "How many names would you like to enter? ";
    int length{};
    std::cin >> length;

    std::string* arr{ new std::string[static_cast<std::size_t>(length)]{} };
    
    // Ignore the line feed that was left by std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for (int i {0}; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin, arr[i]);
    }

    // sort using the default operator<
    std::sort(arr, arr + length);

    std::cout << "Here is your sorted list:" << '\n';
    for (int i{ 0 }; i < length; ++i)
		std::cout << "Name #" << i + 1 << ": " << arr[i] << '\n';
    
    // delete arr
    delete[] arr;
    
    return 0;
}