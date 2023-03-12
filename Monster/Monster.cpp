#include <iostream>

enum monster_type
{
    dragon,
    orc,
    spider,
    slime,
    ogre,

};

struct monster
{
    enum monster_type;
    monster::monster_type type{};
    std::string name{};
    int healt{};
    
};

void printInfo(struct monster& monster)
{
    std::cout << monster.type << " is named " << monster.name << " and has " << monster.healt << " health.\n";
}

int main()
{
    monster monster1 = { monster_type::ogre,"Torg",145};
    printInfo(monster1);
}
