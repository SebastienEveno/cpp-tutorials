#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <iterator> // for std::size
 
int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    constexpr int length{ static_cast<int>(std::size(array)) }; // C++17
    //  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable
    
    for (int j{ 0 }; j < length - 1; ++j)
    {
        bool hasSwapped{ false };
        for (int i{ 0 }; i < length - j - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                hasSwapped = true;
            }
        }
        if (!hasSwapped)
        {
            std::cout << "Early termination on iteration " << j << '\n';
            break;
        }
    }
 
    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';
 
    std::cout << '\n';
 
    return 0;
}