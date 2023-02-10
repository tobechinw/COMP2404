#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Photo.h"


class Album{
    private:
        string title;
        string description;

    public:
        bool equals(string albumTitle);
        bool lessThan(Album album);
        bool addPhoto(Photo photo);
        bool addPhoto(int index, Photo photo);
        void getPhoto(int index);
        void getPhoto(string songTitle);
        void removePhoto(int index);
        void removePhoto(string songTitle);
        int size();
        void print();
        void display();
};





#endif