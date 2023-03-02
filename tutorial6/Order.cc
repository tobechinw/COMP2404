#include "Order.h"

using namespace std;

Order::Order(const string &customerName, int item, Location location1): customerName(customerName), menuItem(item), location(new Location(location1)) {}

Location *Order::getLocation() {
    return location;
}

void Order::print() {
    cout<<"The customer name is "<<customerName<<" and the menu item is "<<menuItem<<endl;
}