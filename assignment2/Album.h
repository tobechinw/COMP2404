#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Photo.h"
#include "PhotoArray.h"


class Album{
    private:
        string title;
        string description;
        PhotoArray *photoArray;

    public:
        Album(const string& title, const string& description);
        Album(const Album &album);
        ~Album();
        string getTitle() const;
        bool equals(string albumTitle) const;
        bool lessThan(Album &alb) const;
        bool addPhoto(Photo* photo);
        bool addPhoto(int index, Photo* photo);
        Photo* getPhoto(int index) const;
        Photo* getPhoto(string title) const;
        Photo* removePhoto(int index);
        Photo* removePhoto(string songTitle);
        int size() const;
        void print() const;
        void display() const;
};





#endif