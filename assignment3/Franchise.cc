#include "Franchise.h"

const string Franchise::menu[MENU_ITEMS] =  {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};
int Franchise::nextId = 0;

Franchise::Franchise(const string& name, Location location1): Entity(Franchise::code, Franchise::nextId, name, location1) {
    Franchise::nextId++;
}

Franchise::Franchise(): Entity(Franchise::code, Franchise::nextId, "Franchise", Location(0,0)) {
    Franchise::nextId++;
}

void Franchise::print() const{
    cout<<"The ID of this entity is "<< id<<", with name "<<name<<". The number of orders is "<<getNumOrders()<<" and the location is ";
    location->print();
    cout<<". This entity is a franchise."<<endl;
}

void Franchise::printMenu(){
    for(int i = 0; i < MENU_ITEMS; ++i){
        cout<<menu[i]<<endl;
    }
}

string Franchise::getMenu(int index){
    if(index < 0 || index > MENU_ITEMS){
        return "unknown menu item";
    }
    return menu[index];
}