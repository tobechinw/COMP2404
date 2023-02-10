#ifndef STACKARRAYS_H
#define STACKARRAYS_H
#include "defs.h"
#include <iostream>
#include <string>
#include "Photo.h"

class StackArrays{
    private:
        Photo photos[ARR_SIZE];
        Photo* photoPointers[ARR_SIZE];
        int numPhotos;
    public:
        StackArrays();
        ~StackArrays();
        Photo* getObjectArray();
        Photo** getPointerArray();
        void addPhoto(Photo photo);
};



#endif