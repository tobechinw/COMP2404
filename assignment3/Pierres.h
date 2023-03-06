#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include "Driver.h"
#include "Franchise.h"
#include <vector>

class Pierres{
private:
    vector<Driver*> drivers;
    vector<Franchise*> franchises;
    Driver* findClosestDriver(Location location) const;
    Franchise* findClosestFranchise(Location location) const;
public:
    Pierres();
    void addDriver(string name, Location location);
    void addFranchise(string name, Location location);
    void takeOrder(string customerName, int menuItem, Location location);
    void driverPickup(string franchiseId, int numOrders);
    void driverDeliver(string driverId, int numOrders);
    void printFranchises() const;
    void printDrivers() const;
};


#endif