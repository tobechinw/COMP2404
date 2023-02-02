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
    Date first = this->checkInDate;
    Date second = r.checkInDate;

    if(first.lessThan(second)){
        int numDays = this->numDays;
        first.addDays(numDays);
        if(!first.lessThan(second) && !first.equals(second)){
            return true;
        }
    }else if(second.lessThan(first)){
        second.addDays(r.numDays);
        if(!second.lessThan(first) && !second.equals(first)){
            return true;
        }
    }
    return false;
}


bool Reservation::lessThan(Reservation &res) {
    if(this->overlaps(res)){
        return false;
    }
    else if(this->checkInDate.lessThan(res.checkInDate)){
        return true;
    }
    return false;
}

bool Reservation::lessThan(Date &d) {
    if(checkInDate.lessThan(d)){
        return true;
    }
    return false;
}

void Reservation::print() {
    cout<<"Reservation for "<<clientName<<"on for "<<numDays<<" days"<<endl;
}