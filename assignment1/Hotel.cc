#include "Hotel.h"


Hotel::Hotel() {
    numRooms = 0;
    for(int i = 0; i < MAX_ROOMS; ++i){
        rooms[i] = new Room(0, "", 0, true);
    }
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr) {
    if(numRooms == MAX_ROOMS){
        return false;
    }
    rooms[numRooms] = new Room(roomNumber, bedType, capacity, fr);
    numRooms+=1;
    return true;
}

bool Hotel::deleteRoom(int roomNumber) {
    if(roomNumber > numRooms){
        return false;
    }
    for(int i = roomNumber; i < numRooms; ++i){
        rooms[i] = rooms[i+1];
    }
    numRooms-=1;
    return true;

}

bool Hotel::getRoom(int roomNumber, Room **room) {
    if(numRooms < roomNumber){
        return false;
    }
    *room = rooms[roomNumber];
    return true;
}

bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date &date, int duration) {
    for(int i = 0; i < numRooms; ++i){
        if(rooms[i]->isMatch(bedType, capacity, fr)){
            if(rooms[i]->addReservation(customer, date, duration)){
                return true;
            }
        }
    }

    return false;

}

void Hotel::updateReservations(Date &currentDate) {
    cout <<"Nothing for now"<<endl;
}

void Hotel::print() {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->printRoom();
    }
}

void Hotel::printReservations() {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->printReservations();
    }
}

