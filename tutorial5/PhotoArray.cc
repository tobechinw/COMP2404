#include "PhotoArray.h"


PhotoArray::PhotoArray() {
    numPhotos = 0;
    photoPtrs = new Photo*[MAX_ARRAY];
}

PhotoArray::PhotoArray(const PhotoArray &photoArr): numPhotos(photoArr.numPhotos){
    photoPtrs = new Photo*[MAX_ARRAY];
    for(int i = 0; i < numPhotos; ++i){
        photoPtrs[i] = new Photo(* (photoArr.photoPtrs[i]) );
//        if(photoArr.photoPtrs[i] != nullptr){
//            photoPtrs[i] = new Photo(* (photoArr.photoPtrs[i]) );
//        }else{
//            photoPtrs[i] = nullptr;
//        }
    }
}

PhotoArray::~PhotoArray() {
    for(int i = 0; i < numPhotos; ++i){
        delete photoPtrs[i];
    }
    delete [] photoPtrs;
}

bool PhotoArray::isFull() {
    return size() == MAX_ARRAY;
}

bool PhotoArray::add(Photo *photo) {
    if(isFull()){
        return false;
    }
    photoPtrs[numPhotos] = photo;
    numPhotos++;
    return true;
}

bool PhotoArray::add(int index, Photo *photo) {
    if(isFull() || index > size() || index < 0){
        return false;
    }
    for(int i = size(); i > index; i--){
        photoPtrs[i] = photoPtrs[i - 1];
    }
    photoPtrs[index] = photo;
    numPhotos++;
    return true;
}

Photo *PhotoArray::get(int index) {
    if(index < 0 || index > size()){
        return nullptr;
    }
    if(photoPtrs[index]){
        return photoPtrs[index];
    }
    return nullptr;
}

Photo *PhotoArray::get(string title) {
    for(int i = 0; i < size(); ++i){
        if(photoPtrs[i]->getTitle() == title){
            return photoPtrs[i];
        }
    }
    return nullptr;
}


Photo *PhotoArray::remove(string title) {
    for(int i = 0; i < size(); ++i){
        if(photoPtrs[i]->getTitle() == title){
            Photo* photo = photoPtrs[i];
            for(int j = i ; j < size(); ++j){
                photoPtrs[j] = photoPtrs[j+1];
            }
            numPhotos--;
            return photo;
        }
    }
    return nullptr;
}

Photo *PhotoArray::remove(int index) {
    if(index < 0 || index > size()){
        return nullptr;
    }
    Photo* photo = photoPtrs[index];
    for(int i = index; i < numPhotos; ++i){
        photoPtrs[i] = photoPtrs[i+1];
    }
    numPhotos--;
    return photo;
}

int PhotoArray::size() {
    return numPhotos;
}

void PhotoArray::display() {
    for(int i = 0; i < numPhotos; ++i){
        photoPtrs[i]->display();
    }
}
