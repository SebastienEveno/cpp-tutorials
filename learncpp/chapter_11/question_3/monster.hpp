#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,

        max_monster_types
    };

    Monster(Type type, const std::string& name, const std::string& roar, int hit_points)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points} {}
    std::string_view getTypeString() const
    {
        switch(m_type)
        {
            case Type::dragon: return "dragon";
            case Type::goblin: return "gobelin";
            case Type::ogre: return "ogre";
            case Type::orc: return "orc";
            case Type::skeleton: return "skeleton";
            case Type::troll: return "troll";
            case Type::vampire: return "vampire";
            case Type::zombie: return "zombie";
            default: return "??";
        }
    }
    
    void print() const
    { 
        std::cout << m_name << " the " << getTypeString() 
        << " has " << m_hit_points << " hit points and says " << m_roar << ".\n"; 
    }

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hit_points{};
};

#endif