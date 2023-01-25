#include "Hotel.h"



//int numRooms;
//Room* rooms;

Hotel::Hotel() {
    numRooms = MAX_ROOMS;
    rooms = new Room[MAX_ROOMS];
//    rooms = newRooms;
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr) {
    if(numRooms == MAX_ROOMS){
        return false;
    }
    return true;
}

bool Hotel::deleteRoom(int roomNumber) {
    return false;

}

bool Hotel::getRoom(int roomNumber, Room **room) {
    for(int i = 0; i < numRooms; ++i){
        if(room[i]->getRoomNumber() == roomNumber){
            *room = room[i];
            return true;
        }
    }

    return false;
}

bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date &date, int duration) {
    return false;

}