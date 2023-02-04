#include "Hotel.h"

//constructor
Hotel::Hotel() {
    numRooms = 0;
}

//destructor for statically allocated memory
Hotel::~Hotel() {
    for(int i = 0; i < numRooms; ++i){
        delete rooms[i];
    }
}

// adds room to a hotel
bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr) {
    if(numRooms == MAX_ROOMS){
        return false;
    }
    for(int i = 0 ; i < numRooms; ++i){
        if(rooms[i]->getRoomNumber() == roomNumber){
            return false;
        }
    }
    Room *room = new Room(roomNumber, bedType, capacity, fr);
    int index = 0;
    while(index < numRooms && rooms[index]->lessThan(*room)){
        index++;
    }
    for(int j = numRooms; j > index; --j){
        rooms[j] = rooms[j - 1];
    }
    rooms[index] = room;
    numRooms++;
    return true;
}

// removes room from a hotel
bool Hotel::deleteRoom(int roomNumber) {
    for(int i = 0; i < numRooms; ++i){
        if(rooms[i]->getRoomNumber() == roomNumber){
            delete rooms[i];
            for(int j = i; j < numRooms; ++j){
                rooms[j] = rooms[j+1];
            }
            numRooms-=1;
            return true;
        }
    }
    return false;
}

// checks if a room with given room number is available, and returns it
bool Hotel::getRoom(int roomNumber, Room **room) {
    for(int i = 0; i < numRooms; ++i){
        if(rooms[i]->getRoomNumber() == roomNumber){
            *room = rooms[i];
            return true;
        }
    }
    return false;
}

// adds reservation to room in hotel that meets criteria
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

// updates reservations given current date
void Hotel::updateReservations(Date &currentDate) {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->updateReservations(currentDate);
    }
}

//prints rooms in hotel
void Hotel::print() {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->printRoom();
    }
}

//prints reservation for each room
void Hotel::printReservations() {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->printReservations();
    }
}

