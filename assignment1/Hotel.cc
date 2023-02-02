#include "Hotel.h"


Hotel::Hotel() {
    numRooms = 0;
}

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

bool Hotel::getRoom(int roomNumber, Room **room) {
    for(int i = 0; i < numRooms; ++i){
        if(rooms[i]->getRoomNumber() == roomNumber){
            *room = rooms[i];
            return true;
        }
    }
    return false;
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
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->updateReservations(currentDate);
    }
    cout <<"Nothing for now"<<endl;
}

void Hotel::print() {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->printRoom();
    }
}

void Hotel::printReservations() {
    for(int i = 0; i < numRooms; ++i){
        rooms[i]->printRoom();
        rooms[i]->printReservations();
    }
}

