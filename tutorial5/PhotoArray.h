#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H
#include <iostream>
#include <string>
#include "Photo.h"
#include "defs.h"


class PhotoArray{
    private:
        Photo ** photoPtrs;
        int numPhotos;
public:
    PhotoArray();
    PhotoArray(const PhotoArray&);
    ~PhotoArray();
    bool isFull();
    bool add(Photo * photo);
    bool add(int index, Photo* photo);
    Photo* get(string title);
    Photo* get(int index);
    Photo* remove(string title);
    Photo* remove(int index);
    int size();
    void display();
};



#endif