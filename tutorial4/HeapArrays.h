#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H
#include <iostream>
#include <string>
#include "defs.h"
#include "Photo.h"

class HeapArrays{
    private:
        Photo* photoObj;
        Photo** photoPtr;
        int numPhotos;
    public:
        HeapArrays();
        ~HeapArrays();
        Photo* getObjectArray();
        Photo** getPointerArray();
        void addPhoto(Photo photo);
};


#endif