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
        string getTitle();
        bool equals(string albumTitle);
        bool lessThan(Album &alb);
        bool addPhoto(Photo* photo);
        bool addPhoto(int index, Photo* photo);
        Photo* getPhoto(int index);
        Photo* getPhoto(string title);
        Photo* removePhoto(int index);
        Photo* removePhoto(string songTitle);
        int size();
        void print();
        void display();
};





#endif