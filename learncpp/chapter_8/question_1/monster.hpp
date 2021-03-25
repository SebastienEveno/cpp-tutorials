#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>
#include <string>

enum class MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime
};

class Monster
{
private:
    MonsterType m_type;
    std::string m_name;
    int m_health;
public:
    Monster(const MonsterType& type, std::string name, int health) : m_type{type}, m_name{name}, m_health{health} {}
    std::string getMonsterTypeAsString(const MonsterType& type) const
    {
        switch(type)
        {
            case MonsterType::Ogre:
                return "Ogre";
            case MonsterType::Dragon:
                return "Dragon";
            case MonsterType::Orc:
                return "Orc";
            case MonsterType::GiantSpider:
                return "GiantSpider";
            case MonsterType::Slime:
                return "Slime";
            default:
                return "??"; 
        }
    }
    void printMonster() const
    {
        std::cout << "This " << getMonsterTypeAsString(m_type) << " is named "<< m_name << " and has " << m_health << " health.\n";
    }
};

#endif