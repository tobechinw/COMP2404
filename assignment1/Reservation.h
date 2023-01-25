#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include "Date.h"

class Reservation{
    public:
        //constructor
        Reservation(string customerName, Date& checkIn, int duration);

        void setDuration(int duration);
        bool overlaps(Reservation& r);
        bool lessThan(Reservation& res);
        bool lessThan(Date& d);
        void print();
    private:
        string clientName;
        Date checkInDate;
        int numDays;
};






#endif