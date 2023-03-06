#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Entity.h"

class Driver: public Entity{
private:
    static const char code = 'D';
    static int nextId;

public:
    Driver(const string& name, Location location1);
    Driver(const string& name);
    bool isFree() const;
    void print() const;
};







#endif