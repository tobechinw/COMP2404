#ifndef ENTITY_H
#define ENTITY_H


#include <string>
#include "Location.h"
#include "Queue.h"
#include <iostream>

class Entity{
protected:
    string id;
    string name;
    Location* location;
    Queue* orders;

public:
    Entity(char, int, const string&, Location);
    Location* getLocation() const;
    void setLocation(Location location1);
    int getNumOrders() const;
    Order* getNextOrder();
    void addOrder(Order* order);
    void print() const;
    bool equals(string otherID) const;

};






#endif