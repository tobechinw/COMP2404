#include "Room.h"
using namespace std;

// constructor
Room::Room(int roomNum, string bt, int cap, bool fridge) {
    roomNumber = roomNum;
    bedType = bt;
    capacity = cap;
    hasFridge = fridge;
    numReservations = 0;
}

// destructor
Room::~Room() {
    for(int i = 0; i < numReservations; ++i){
        delete reservations[i];
    }
}

// getter for the room number
int Room::getRoomNumber() {
    return roomNumber;
}

// checks if room meets criteria specified in the parameters
bool Room::isMatch(string bt, int cap, bool f) {
    if(bedType == bt && capacity >= cap ){
        if (f) {
            if (f == hasFridge) {
                return true;
            }
        } else {
            if (!hasFridge) {
                if (f == hasFridge || !hasFridge) {
                    return true;
                }
            } else {
                return true;
            }
        }
    }
    return false;
}

// checks if one room is less than another, according to room number
bool Room::lessThan(Room &r) {
    return roomNumber < r.roomNumber;
}

// adds a reservation for a room
bool Room::addReservation(string customerName, Date &d, int duration) {
    if(numReservations == MAX_RES){
        return false;
    }
    Reservation* reservation = new Reservation(customerName, d, duration);
    for(int i = 0 ; i < numReservations; ++i){
        if(reservation->overlaps(*reservations[i])){
            delete reservation;
            return false;
        }
    }
    int index = 0;
    while(index < numReservations && reservations[index]->lessThan(*reservation) ){
        index++;
    }
    for(int j = numReservations; j > index; --j){
        reservations[j] = reservations[j - 1];
    }
    reservations[index] = reservation;
    numReservations++;
    return true;
}

// prints room information
void Room::printRoom(){
    cout<<"Room Number: "<<roomNumber<<endl<<"Bed Type: "<<bedType<<endl<<"Capacity: "<<capacity<<endl<<"Fridge?: "<<hasFridge<<endl;
}

// prints reservation for room
void Room::printReservations() {
    printRoom();
    cout<<"These are the reservations for Room "<<this->getRoomNumber()<<endl;
    for(int i = 0; i < numReservations; ++i){
        reservations[i]->print();
    }
}

// updates reservation for room, according to current date
void Room::updateReservations(Date &currentDate) {
    for(int i = 0; i < numReservations; ++i){
        if(reservations[i]->lessThan(currentDate)){
            delete reservations[i];
            for(int j = i; j < numReservations - 1; ++j){
                reservations[j] = reservations[j + 1];
            }
            i-=1;
            numReservations--;
        }
    }
}