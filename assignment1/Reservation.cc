#include "Reservation.h"
using namespace std;

// constructor
Reservation::Reservation(string customerName, Date &checkIn, int duration) {
    clientName = customerName;
    checkInDate = checkIn;
    numDays = duration;
}

// sets duration of stay
void Reservation::setDuration(int duration) {
    numDays = duration;
    if(duration < 1){
        numDays = 1;
    }
}

// checks if two reservations overlap
bool Reservation::overlaps(Reservation &r) {
    Date first = this->checkInDate;
    Date second = r.checkInDate;

    if(first.lessThan(second)){
        int numDays = this->numDays;
        first.addDays(numDays);
        if(!first.lessThan(second) && !first.equals(second)){
            return true;
        }
        return false;
    }else if(second.lessThan(first)){
        second.addDays(r.numDays);
        if(!second.lessThan(first) && !second.equals(first)){
            return true;
        }
        return false;
    }
    if(r.numDays > 0 && numDays > 0){
        return true;
    }
    return false;
}

// checks if reservation is less than reservation being compared to it, according to check in date and duration
bool Reservation::lessThan(Reservation &res) {
    if(this->overlaps(res)){
        return false;
    }
    else if(this->lessThan(res.checkInDate)){
        return true;
    }
    Date date = this->checkInDate;
    date.addDays(this->numDays);
    if(date.equals(res.checkInDate)){
        return true;
    }
    return false;
}

// helper function for function above
bool Reservation::lessThan(Date &d) {
    return this->checkInDate.lessThan(d);
}

//print reservation
void Reservation::print() {
    cout<<"Reservation for "<<clientName<<" on ";
    this->checkInDate.print();
    cout<<endl;
}