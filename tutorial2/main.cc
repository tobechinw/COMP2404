#include <iostream>
#include <string>
#include "Character.h"
#include "battle.h"

using namespace std;
using namespace Gondor;
using namespace Mordor;

int main(){
    string name;
    int maxHealth;
    int damage;
    cout<<"Enter in fighter parameters"<<endl;
    cin>>name>>maxHealth>>damage;

    Character fighter = Character(name, maxHealth, damage);

    cout<<"Enter in orc parameters"<<endl;
    cin>>name>>maxHealth>>damage;
    Character orc = Character(name, maxHealth, damage);

    fighter.print();
    orc.print();

    Gondor::fight(fighter, orc);
    Mordor::fight(fighter, orc);


    fighter.print();
    orc.print();




    return 0;
}