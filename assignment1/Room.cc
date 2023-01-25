#include "Room.h"
using namespace std;

Room::Room(int roomNum, string bt, int cap, bool fridge) {
    roomNumber = roomNum;
    bedType = bt;
    capacity = cap;
    hasFridge = fridge;
    numReservations = 0;
}

int Room::getRoomNumber() {
    return roomNumber;
}

bool Room::isMatch(string bt, int cap, bool f) {
    if(strcmp(bedType, bt) == 0 && capacity >= cap && !(hasFridge ^ f)){
        return true;
    }
    return false;
}

bool Room::lessThan(Room &r) {
    return roomNumber < r.roomNumber;
}

bool Room::addReservation(string customerName, Date &d, int duration) {
    if(numReservations == MAX_RES){
        return false;
    }
    return true;
}

void Room::printReservations() {
    cout<<"Room Number: "<<roomNumber<<endl<<"Bed Type: "<<bedType<<endl<<"Capacity: "<<capacity<<endl<<"Fridge?: "<<hasFridge<<endl;
    for(int i = 0; i < numReservations; ++i){
        reservations[i]->print();
    }
}