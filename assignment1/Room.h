#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <cstring>
#include "defs.h"
#include "Reservation.h"

class Room{
    public:
        //constructor
        Room(int roomNumber, string bedType, int capacity, bool hasFridge);
        //destructor
        ~Room();


        //getter
        int getRoomNumber();


        //helper functions
        bool isMatch(string bt, int cap, bool f);
        bool lessThan(Room& r);
        bool addReservation(string customerName, Date& d, int duration);
        void printRoom();
        void printReservations();
        void updateReservations(Date& currentDate); //bonus function
    private:
        int roomNumber;
        string bedType;
        int capacity;
        bool hasFridge;
        Reservation* reservations[MAX_RES];
        int numReservations;
};





#endif