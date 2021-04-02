#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "random.hpp"
#include "potion.hpp"

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;
public:
    Creature(const std::string& name, char symbol, int health, int damage, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold} {}
    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int health_amount)
    {
        if(m_health - health_amount >= 0)
            m_health -= health_amount;
        else
            m_health = 0;
    }

    bool isDead() const { return m_health == 0; }

    void addGold(int gold_amount) { m_gold += gold_amount; }

};

class Player : public Creature
{
private:
    int m_level{ 1 };
public:
    Player(const std::string& name) : Creature{ name, '@', 10, 1, 0 } {}

    int getLevel() const { return m_level; }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    bool hasWon() const { return m_level >= 20; }

    void drinkPotion(const Potion& potion)
    {
        switch(potion.getType())
        {
            case Potion::Type::health:
                m_health += (potion.getEffect() == Potion::Effect::large) ? 5 : 2;
                break;
            case Potion::Type::strength:
                ++m_damage;
                break;
            case Potion::Type::poison:
                reduceHealth(1);
                break;
            case Potion::Type::max_types:
                break;
        }
    }
};

class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };
    
    Monster(Type type) : Creature{ getDefaultCreature(type) } {}
    
    static Monster getRandomMonster()
    {
        int random_number{ getRandomNumber(0, static_cast<int>(Type::max_types) - 1) };
        return Monster(static_cast<Type>(random_number));
    }

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            { { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }
};

void attackMonster(Player& player, Monster& monster)
{
    // If the player is dead, we can't attack the monster
    if (player.isDead())
        return;
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
    // Reduce the monster's health by the player's damage
    monster.reduceHealth(player.getDamage());

    // If the monster is now dead, level the player up
    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());

        // 30% chance of finding a potion
        constexpr int potionChance{ 30 };
        if (getRandomNumber(1, 100) <= potionChance)
        {
            // Generate a random potion
            auto potion{ Potion::getRandomPotion() };
        
            std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
            char choice{};
            std::cin >> choice;
        
            if (choice == 'y')
            {
                // Apply the effect
                player.drinkPotion(potion);
                // Reveal the potion type and size
                std::cout << "You drank a " << potion.getName() << '\n';
            }
        }
    }
}

void attackPlayer(const Monster& monster, Player& player)
{
    // If the monster is dead, it can't attack the player
    if (monster.isDead())
        return;
    
    // Reduce the player's health by the monster's damage
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

// This function handles the entire fight between a player and a randomly generated monster
void fightMonster(Player& player)
{
    // First randomly generate a monster
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
    // While the monster isn't dead and the player isn't dead, the fight continues
    while (!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char input{};
        std::cin >> input;
        if (input == 'R' || input == 'r')
        {
            // 50% chance of fleeing successfully
            if (getRandomNumber(1, 2) == 1)
            {
                std::cout << "You successfully fled.\n";
                return; // success ends the encounter
            }
            else
            {
                // Failure to flee gives the monster a free attack on the player
                std::cout << "You failed to flee.\n";
                attackPlayer(monster, player);
                continue;
            }
        }

        if (input == 'F' || input == 'f')
        {
            // Player attacks first, monster attacks second
            attackMonster(player, monster);
            attackPlayer(monster, player);
        }
    }
}

#endif