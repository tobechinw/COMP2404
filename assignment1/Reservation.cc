#include "Reservation.h"
using namespace std;


Reservation::Reservation(string customerName, Date &checkIn, int duration) {
    clientName = customerName;
    checkInDate = checkIn;
    numDays = duration;
}

void Reservation::setDuration(int duration) {
    numDays = duration;
    if(duration < 1){
        numDays = 1;
    }
}

bool Reservation::overlaps(Reservation &r) {
    return true;
}


bool Reservation::lessThan(Reservation &res) {
    return true;
}

bool Reservation::lessThan(Date &d) {
    return true;
}

void Reservation::print() {
    cout<<"Reservation for "<<clientName<<"on for "<<numDays<<" days"<<endl;
}