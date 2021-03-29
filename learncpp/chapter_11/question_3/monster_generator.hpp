#ifndef MONSTER_GENERATOR_HPP
#define MONSTER_GENERATOR_HPP

#include "monster.hpp"
#include <array>

class MonsterGenerator
{
public:
    static int getRandomNumber(int min, int max)
    {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }

    static Monster generateMonster()
    {
        Monster::Type type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)) };
        int hit_points{ getRandomNumber(1, 100) };

        static constexpr std::array s_names{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
        static constexpr std::array s_roars{"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
        std::string name{ s_names[static_cast<std::size_t>(getRandomNumber(0, s_names.size() - 1))] };
        std::string roar{ s_roars[static_cast<std::size_t>(getRandomNumber(0, s_roars.size() - 1))] };
        
        return { type, name, roar, hit_points };
    }
    
};

#endif
