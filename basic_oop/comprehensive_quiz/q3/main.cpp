// https://www.learncpp.com/cpp-tutorial/8-15-chapter-8-comprehensive-quiz/

// Question #3

#include <string>
#include <string_view>
#include <iostream>
#include <array> // for std::array
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

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
    
    Monster(Type type, 
            const std::string& name, 
            const std::string& roar, 
            int hit_points)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points}
    {
    }

    std::string_view getTypeString() const
    {
        switch(m_type)
        {
            case Type::dragon:
                return "dragon";
            case Type::goblin:
                return "goblin";
            case Type::ogre:
                return "ogre";
            case Type::orc:
                return "orc";
            case Type::skeleton:
                return "skeleton";
            case Type::troll:
                return "troll";
            case Type::vampire:
                return "vampire";
            case Type::zombie:
                return "zombie";
            default:
                return "?";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hit_points << " hit points and says " << m_roar << '\n';
    }

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hit_points{};
};

class MonsterGenerator
{
public:
    // Generate a random number between min and max (inclusive)
	// Assumes std::srand() has already been called
	// Assumes max - min <= RAND_MAX
    static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}

    static Monster generateMonster()
    {
        Monster::Type type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1))};
        int hit_points{ getRandomNumber(0, 100)};
        static constexpr std::array s_names{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
        static constexpr std::array s_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
        return { type, s_names[getRandomNumber(0, static_cast<int>(s_names.size() - 1))], s_roars[getRandomNumber(0, static_cast<int>(s_names.size() - 1))], hit_points };
    }
};

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value
 
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();
 
	return 0;
}

