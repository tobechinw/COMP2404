#ifndef HOTEL_H
#define HOTEL_H
#include "Room.h"
#include "Reservation.h"
#include "defs.h"




class Hotel{
    private:
        Room* rooms[MAX_ROOMS];
        int numRooms;
public:
        //constructor
        Hotel();
        //destructor
        ~Hotel();

        bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
        bool deleteRoom(int roomNumber);
        bool getRoom(int roomNumber, Room **room);
        bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
        void updateReservations(Date& currentDate); //bonus function
        void print();
        int requestReservation();
        void printReservations();

};



#endif