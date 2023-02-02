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

bool Room::lessThan(Room &r) {
    return roomNumber < r.roomNumber;
}

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
//    delete reservations[index];
    for(int j = numReservations; j > index; --j){
        reservations[j] = reservations[j - 1];
    }
    reservations[index] = reservation;
    numReservations++;
    return true;
}

void Room::printRoom(){
    cout<<"Room Number: "<<roomNumber<<endl<<"Bed Type: "<<bedType<<endl<<"Capacity: "<<capacity<<endl<<"Fridge?: "<<hasFridge<<endl;
}

void Room::printReservations() {
    cout<<"Room Number: "<<roomNumber<<endl<<"Bed Type: "<<bedType<<endl<<"Capacity: "<<capacity<<endl<<"Fridge?: "<<hasFridge<<endl;
    for(int i = 0; i < numReservations; ++i){
        reservations[i]->print();
    }
}

void Room::updateReservations(Date &currentDate) {
    for(int i = 0; i < numReservations; ++i){
        if(reservations[i]->lessThan(currentDate)){
            delete reservations[i];
            for(int j = i; j < numReservations - 1; ++j){
                reservations[j] = reservations[j + 1];
            }
            numReservations--;
        }
    }
}