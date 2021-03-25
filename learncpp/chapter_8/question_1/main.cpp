#include "monster.hpp"

int main()
{
    Monster ogre{ MonsterType::Ogre, "Torg", 145 };
    Monster slime{ MonsterType::Slime, "Blurp", 23 };

    ogre.printMonster();
    slime.printMonster();
    
    return 0;
}