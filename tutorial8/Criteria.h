#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Photo.h"
using namespace std;


class Criteria{
    friend ostream& operator<<(ostream&, const Criteria&);
    public:
        virtual bool matches(const Photo& photo) const = 0;
        virtual void print(ostream& os) const = 0;
};

class Cat_Criteria: virtual public Criteria{
    public:
        string category;
        Cat_Criteria(const string& category);
        virtual bool matches(const Photo &photo) const override{
            return category == photo.getCategory();
        }
        virtual void print(ostream &os) const override{
            os<<"The category is "<<category<<endl;
        }
};

class Date_Criteria: virtual public Criteria{
    public:
        Date startDate;
        Date endDate;
        Date_Criteria(const Date& startDate, const Date& endDate);
        virtual bool matches(const Photo &photo) const override{
            cout<<"in date matches function"<<endl;
            return (photo.getDate() >= startDate && photo.getDate() <= endDate);
        }
        virtual void print(ostream &os) const override{
            os<<"Start date is ";
            startDate.print(os);
            os<<" and end date is ";
            endDate.print(os);
            os<<endl;
        }
};

class CandD_Criteria: public Date_Criteria, public Cat_Criteria {
    public:

        CandD_Criteria(const Date& start, const Date& end, const string& myCategory): Cat_Criteria(myCategory), Date_Criteria(start, end){
            cout<<"candd constructor, category is "<<category<<endl;
        }
//    protected:
//        Date startDate;
//        Date endDate;
//        string category;
        virtual bool matches(const Photo &photo) const override{
            return Date_Criteria::matches(photo) && Cat_Criteria::matches(photo);
//            cout<<"category is "<<category<<endl;
//            cout<<"photo category is "<<photo.getCategory()<<endl;
//            return category == photo.getCategory() && photo.getDate() >= startDate && photo.getDate() <= endDate;
        }

        virtual void print(ostream &os) const override{
            os<<"Category is "<<category<<endl;
            os<<"Start date is ";
            startDate.print(os);
            os<<endl<<"End date is ";
            endDate.print(os);
            os<<endl;
        }
};




#endif