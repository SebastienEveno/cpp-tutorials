#include <iostream>
#include <string>

enum class MonsterType {
    ogre,
    dragon,
    orc,
    giant_spider,
    slime
};

struct Monster {
    MonsterType type;
    std::string name;
    int health;
};

void printMonster(Monster monster) {
    std::string monster_type;
    if (monster.type == MonsterType::ogre)
        monster_type = "Ogre";
    else if (monster.type == MonsterType::dragon)
        monster_type = "Dragon";
    else if (monster.type == MonsterType::orc)
        monster_type = "Orc";
    else if (monster.type == MonsterType::giant_spider)
        monster_type = "Giant Spider";
    else 
        monster_type = "Slime";
    std::cout << "This " << monster_type << " is named " << monster.name << " and has " << monster.health << " health." << '\n';
}

int main()
{
    Monster monster_1{ MonsterType::ogre, "Torg", 145 };
    Monster monster_2{ MonsterType::slime, "Blurp", 23 };
    
    printMonster(monster_1);
    printMonster(monster_2);

    return 0;
}