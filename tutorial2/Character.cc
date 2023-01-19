#include "Character.h"
#include <iostream>

using namespace std;


Character::Character(string name, int maxHealth, int damage) {
    this->name = name;
    this->maxHealth = maxHealth;
    this->damage = damage;
    this->currentHealth = maxHealth;
}

string Character::getName() {
    return name;
}

void Character::takeDamage(int damage) {
    this->currentHealth -= damage;

    if(this->currentHealth < 0){
        this->currentHealth = 0;
    }
}

int Character::strike() {
    return damage;
}

void Character::print() {
    cout<<name<<" has a current health of "<<currentHealth<<endl;
}
