#include <iostream>

int main() 
{
    constexpr std::string_view arr[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    
    std::cout << "Enter a name: ";
    std::string name{};
    std::cin >> name;

    bool found{ false };
    for (auto &element : arr)
    {
        if (element == name)
        {
            found = true;
            break;
        }
    }
    
    if (found)
        std::cout << name << " was found.";
    else
        std::cout << name << " was not found.";
    
    return 0;
}