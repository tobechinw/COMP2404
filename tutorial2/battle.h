#ifndef BATTLE_H
#define BATTLE_H
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;


namespace Gondor{
    void fight(Character& fighter, Character &orc);
}

namespace Mordor{
    void fight(Character& fighter, Character &orc);
}


#endif