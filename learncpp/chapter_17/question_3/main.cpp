#include <iostream>
#include "creature.hpp"

int main()
{
	Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    
	return 0;
}

