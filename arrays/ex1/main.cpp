#include <iostream>

namespace Animals
{
    enum Animals {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };
}

int main() 
{
    int arr[Animals::max_animals] { 2, 4, 4, 4, 2, 0 };
    std::cout << "An elephant has " << arr[Animals::elephant] << " legs.\n"; 
    
    return 0;
}