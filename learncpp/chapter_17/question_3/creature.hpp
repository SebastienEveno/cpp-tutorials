#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int getRandomNumber(int min, int max)
{
  static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
  // evenly distribute the random number across our range
  return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

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

#endif