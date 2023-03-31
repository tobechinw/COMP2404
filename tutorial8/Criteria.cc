#include "Criteria.h"


Date_Criteria::Date_Criteria(const Date &startDate, const Date &endDate): startDate(startDate), endDate(endDate) {}


Cat_Criteria::Cat_Criteria(const string &myCategory): category(myCategory) {}

ostream& operator<<(ostream& os, const Criteria& criteria){
    criteria.print(os);
    return os;
}

