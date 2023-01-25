#include "Reservation.h"
using namespace std;


Reservation::Reservation(string customerName, Date &checkIn, int duration) {
    clientName = customerName;
    checkInDate = checkIn;
    numDays = duration;
}

void Reservation::setDuration(int duration) {
    numDays = duration;
}

bool Reservation::overlaps(Reservation &r) {

}


bool Reservation::lessThan(Reservation &res) {

}

bool Reservation::lessThan(Date &d) {

}

void Reservation::print() {
    cout<<"Reservation for "<<clientName<<"on "<<checkInDate.print()<<"for "<<numDays<<" days"<<endl;
}