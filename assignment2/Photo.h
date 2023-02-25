#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Date.h"

class Photo{
    private:
        string title;
        string photoContent;
        Date* createdAt;

    public:
        Photo();
        ~Photo();
        Photo(const Photo&);
        Photo(const string& photoTitle, const Date& date, const string& photoContent);
        bool equals(string title) const;
        string getTitle() const;
        void print() const;
        void display() const;
};


#endif