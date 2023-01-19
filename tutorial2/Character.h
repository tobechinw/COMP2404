#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class Character{
    public:
        Character(string name, int maxHealth, int damage);

        string getName();
        void takeDamage(int damage);
        int strike();
        void print();

    private:
        string name;
        int maxHealth;
        int currentHealth;
        int damage;
};


#endif