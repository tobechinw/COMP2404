#include "Entity.h"

using namespace std;


Entity::Entity(char idChar, int idInt, const string& entName, Location location1): id( idChar + to_string(idInt )), name(entName){
    location = new Location(location1.getX(), location1.getY());
    orders = new Queue();
}

Entity::~Entity() {
    delete orders;
    delete location;
}

void Entity::setLocation(Location location1) {
    location->setLocation(location1.getX(), location1.getY());
}

int Entity::getNumOrders() const{
    return orders->size();
}

Order *Entity::getNextOrder() {
    return orders->popFirst();
}

void Entity::addOrder(Order *order) {
    return orders->addLast(order);
}

Location *Entity::getLocation() const{
    return location;
}

void Entity::print() const{
    cout<<"The ID of this entity is "<< id<<", with name "<<name<<". The number of orders is "<<getNumOrders()<<" and the location is ";
    location->print();
    cout<<endl;
}

bool Entity::equals(string otherID) const {
    return id == otherID;
}
