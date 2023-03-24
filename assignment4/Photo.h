#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Date.h"

class Photo{
    friend ostream& operator<<(ostream&, const Photo&);
    private:
        string title;
        string photoContent;
        string category;
        Date* createdAt;

    public:
        Photo();
        ~Photo();
        Photo(const Photo&);
        Photo(const string& photoTitle, const string& category, const Date& date, const string& photoContent);
        bool equals(string title) const;
        string getTitle() const;
        const string& getCategory() const;
        const Date& getDate() const;
        void print(ostream& os) const;
        void display(ostream& os) const;
};


#endif