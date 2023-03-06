#include "Driver.h"

using namespace std;

int Driver::nextId = 0;

Driver::Driver(): Entity(code, nextId, "Tobechi", Location(0, 0)) {
    nextId++;
}

Driver::Driver(const string& name, Location location1): Entity(code, nextId, name, location1){
    nextId++;
}

bool Driver::isFree() const{
    return orders->empty();
}

void Driver::print() const{
    cout<<"The ID of this entity is "<< id<<", with name "<<name<<". The number of orders is "<<getNumOrders()<<" and the location is ";
    location->print();
    cout<<". This entity is a driver."<<endl;
}