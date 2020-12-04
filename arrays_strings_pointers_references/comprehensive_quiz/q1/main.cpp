/*Pretend you’re writing a game where the player 
can hold 3 types of items: health potions, torches, 
and arrows. Create an enum to identify the different 
types of items, and an std::array to store the number of each
item the player is carrying (The enumerators are used as indexes
of the array). The player should start with 2 health potions,
5 torches, and 10 arrows. 
Write a function called countTotalItems() that returns 
how many items the player has in total. Have your main()
function print the output of countTotalItems() as well as
the number of torches.*/

// https://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/

#include <array>
#include <iostream>
#include <numeric> // std::reduce

enum Items
{
    health_potions,
    torches,
    arrows,
    max_items
};

using inventory_type = std::array<int, Items::max_items>;

int countTotalItems(const inventory_type& arr)
{
    return std::accumulate(arr.begin(), arr.end(), 0);
}

int main()
{
    inventory_type items { 2, 5, 10 };
    std::cout << "Number of items the player has in total: " << countTotalItems(items) << '\n';
    std::cout << "Number of torches: " << items[Items::torches] << '\n';

    return 0;
}