#include <array>
#include <numeric>
#include <iostream>

enum class Items
{
    potions,
    torches,
    arrows,
    max_items
};

class Player
{
private:
    std::array<int, static_cast<int>(Items::max_items)> m_items;
public:
    Player(int number_of_potions=2, int number_of_torches=5, int number_of_arrows=10)
    {
        m_items = {number_of_potions, number_of_torches, number_of_arrows};
    }
    int countTotalItems() const
    {
        return std::accumulate(m_items.begin(), m_items.end(), 0);
    }
};

int main()
{
    Player player_1;
    std::cout << "This player has " << player_1.countTotalItems() << " items. \n";
    return 0;
}