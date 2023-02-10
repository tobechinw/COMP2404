#include "StackArrays.h"


StackArrays::StackArrays(): numPhotos(0) {}

StackArrays::~StackArrays() {
    for(int i = 0; i < numPhotos; ++i){
        delete photoPointers[i];
    }
}

Photo* StackArrays::getObjectArray() {
    return photos;
}

Photo** StackArrays::getPointerArray() {
    return photoPointers;
}

void StackArrays::addPhoto(Photo photo) {
    if(numPhotos < ARR_SIZE){
        photos[numPhotos] = photo;
        photoPointers[numPhotos] = new Photo(photo);
        numPhotos++;
    }
}