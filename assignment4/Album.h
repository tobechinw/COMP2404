#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Photo.h"


class Album{
    friend ostream& operator<<(ostream& os, const Album& album);


    private:
        string title;
        string description;
        Array<Photo*> photoArray;


    public:
        Album(const string& title, const string& description);
//        Album(const Album &album);
        ~Album();
        string getTitle() const;
        bool equals(string albumTitle) const;
//        bool lessThan(Album &alb) const;
        void addPhoto(Photo* photo);
//        bool addPhoto(int index, Photo* photo);
        Photo* getPhoto(int index) const;
//        Photo* getPhoto(string title) const;
//        Photo* removePhoto(int index);
//        Photo* removePhoto(string songTitle);
        int size() const;
        void print(ostream& os) const;
        void display(ostream& os) const;
};





#endif