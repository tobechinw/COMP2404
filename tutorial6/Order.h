#ifndef ORDER_H
#define ORDER_H

#include "Location.h"

#include <iostream>


class Order{
    private:
        string customerName;
        int menuItem;
        Location* location;
    public:
        Order(const string &customerName, int item, Location location1);
        Location * getLocation();
        void print();
};



#endif