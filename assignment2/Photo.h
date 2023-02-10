#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Date.h"

class Photo{
    private:
        const string& title;
        const string& content;
        const Date& createdAt;

    public:
        Photo(const string& photoTitle, const Date& date, const string& photoContent);
        bool equals(string title);
        void print();
        void display();
};


#endif