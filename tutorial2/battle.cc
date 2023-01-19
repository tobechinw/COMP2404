#include "battle.h"
using namespace Gondor;
using namespace Mordor;


void Gondor::fight(Character &fighter, Character &orc) {
    orc.takeDamage(fighter.strike() - 1);
    fighter.takeDamage(orc.strike() + 1);
    string fighterName = fighter.getName();
    string orcName = orc.getName();
    cout<<fighterName<<" hits "<<orcName<<" for "<<fighter.strike()<<" damage"<<endl;
}

void Mordor::fight(Character &fighter, Character &orc) {
    orc.takeDamage(fighter.strike() + 1);
    fighter.takeDamage(orc.strike() - 1);
    string fighterName = fighter.getName();
    string orcName = orc.getName();
    cout<<orcName<<" hits "<<fighterName<<" for "<<orc.strike()<<" damage"<<endl;
}