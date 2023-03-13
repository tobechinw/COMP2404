#include "Pierres.h"


Pierres::Pierres() {}

Pierres::~Pierres() {
    for(int i = 0; i < drivers.size(); ++i){
        delete drivers.at(i);
    }
    for(int j = 0; j < franchises.size(); ++j){
        delete franchises.at(j);
    }
}

void Pierres::addDriver(string name, Location location) {
    Driver* driver = new Driver(name, location);
    drivers.push_back(driver);
}

void Pierres::addFranchise(string name, Location location) {
    Franchise* franchise = new Franchise(name, location);
    franchises.push_back(franchise);
}

void Pierres::takeOrder(string customerName, int menuItem, Location location) {
    Order* order = new Order(customerName, menuItem, location);
    Franchise* franchise = findClosestFranchise(location);
    if(franchise != nullptr){
        franchise->addOrder(order);
    }
}

void Pierres::driverPickup(string franchiseId, int numOrders) {
    Franchise* franchise = nullptr;
    for(int i = 0; i < franchises.size(); ++i){
        if(franchises.at(i)->equals(franchiseId)){
            franchise = franchises.at(i);
        }
    }
    if(franchise == nullptr){
        cout<<"Franchise with that ID does not exist"<<endl;
        return;
    }
    if(franchise->getNumOrders() == 0){
        cout<<"Franchise has no orders"<<endl;
        return;
    }
    Driver* driver = findClosestDriver(*franchise->getLocation());
    if(driver == nullptr){
        cout<<"Driver not found"<<endl;
        return;
    }
    driver->setLocation(*(franchise->getLocation()));

    if(numOrders > franchise->getNumOrders()){
        cout<<"Number of orders is more than what the franchise has, so the driver will pick up all the orders"<<endl;
        numOrders = franchise->getNumOrders();
    }

    for(int i = 0; i < numOrders; ++i){
        driver->addOrder(franchise->getNextOrder());
    }
    cout<<"Driver has picked up orders and is on the move"<<endl;
}

void Pierres::driverDeliver(string driverId, int numOrders) {
    Driver* driver = nullptr;
    for(int i = 0; i < drivers.size(); ++i){
        if(drivers.at(i)->equals(driverId)){
            driver = drivers.at(i);
        }
    }
    if(driver == nullptr){
        cout<<"Driver with that ID does not exist"<<endl;
        return;
    }
    if(driver->getNumOrders() == 0){
        cout<<"Driver has no orders"<<endl;
        return;
    }

    if(numOrders > driver->getNumOrders()){
        cout<<"Number of orders is more than what the driver has, so the driver will deliver all orders"<<endl;
        numOrders = driver->getNumOrders();
    }


    for(int i = 0; i < numOrders; ++i){
        Order* order = driver->getNextOrder();
        Location location = *(order->getLocation());
        driver->setLocation(location);
        cout<<"Delivering at ";
        location.print();
        delete order;
        cout<<endl;
    }
    cout<<"Driver has made all deliveries"<<endl;
}

void Pierres::printFranchises() const{
    for(int i = 0; i < franchises.size(); ++i){
        franchises.at(i)->print();
    }
}

void Pierres::printDrivers() const{
    for(int i = 0; i < drivers.size(); ++i){
        drivers.at(i)->print();
    }
}

Driver* Pierres::findClosestDriver(Location location) const{
    if(drivers.empty()){
        return nullptr;
    }
    Driver* closest = drivers.at(0);
    int closestDistance = location.getDistance(*drivers.at(0)->getLocation());

    for(int i = 1; i < drivers.size(); ++i){
        Driver* tmp = drivers.at(i);
        int tmpDistance = location.getDistance( *(tmp->getLocation()) );
        if(tmpDistance < closestDistance && tmp->isFree()){
            closestDistance = tmpDistance;
            closest = tmp;
        }
    }

    return closest;
}

Franchise* Pierres::findClosestFranchise(Location location) const{
    if(franchises.empty()){
        return nullptr;
    }

    Franchise* closest = franchises.at(0);
    int closestFranchise = location.getDistance(*franchises.at(0)->getLocation());

    for(int i = 1; i < franchises.size(); ++i){
        Franchise* tmp = franchises.at(i);
        int tmpDistance = location.getDistance(*(tmp->getLocation()));
        if(tmpDistance < closestFranchise){
            closestFranchise = tmpDistance;
            closest = tmp;
        }
    }

    return closest;
}