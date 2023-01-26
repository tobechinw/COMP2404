#include "Character.h"
#include <iostream>

using namespace std;


Character::Character(const string& name, int maximumHealth, int damage) {
    this->name = name;
    this->maxHealth = maximumHealth;
    this->damage = damage;
    this->currentHealth = maximumHealth;
}

string Character::getName() {
    return name;
}

void Character::takeDamage(int damage) {
    currentHealth -= damage;

    if(currentHealth < 0){
        currentHealth = 0;
    }
}

int Character::strike() {
    return damage;
}

void Character::print() {
    cout<<name<<" has a health of "<<currentHealth<<endl;
}
