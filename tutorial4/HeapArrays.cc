#include "HeapArrays.h"




HeapArrays::HeapArrays() {
    photoPtr = new Photo*[ARR_SIZE];
    photoObj = new Photo[ARR_SIZE];
    numPhotos = 0;
}

HeapArrays::~HeapArrays() {
    delete[] photoObj;
    for(int i = 0; i < numPhotos; ++i){
        delete photoPtr[i];
    }
    delete[] photoPtr;
}


Photo* HeapArrays::getObjectArray() {
    return photoObj;
}

Photo** HeapArrays::getPointerArray() {
    return photoPtr;
}


void HeapArrays::addPhoto(Photo photo) {
    if(numPhotos < ARR_SIZE){
        photoObj[numPhotos] = photo;
        photoPtr[numPhotos] = new Photo(photo);
        numPhotos++;
    }
}

