#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

#include "monster.hpp"
#include "monster_generator.hpp"

int main()
{
    // set initial seed value to system clock
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // set initial seed value to system clock
	// std::rand();

	Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

    Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}