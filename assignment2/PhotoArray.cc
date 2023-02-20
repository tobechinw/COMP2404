#include "PhotoArray.h"
using namespace std;

PhotoArray::PhotoArray() {
    numPhotos = 0;
    photoPtrs = new Photo*[MAX_ARRAY];
}

PhotoArray::PhotoArray(const PhotoArray &photoArr): numPhotos(photoArr.numPhotos){
    photoPtrs = new Photo*[MAX_ARRAY];
    for(int i = 0; i < numPhotos; ++i){
        photoPtrs[i] = new Photo(*photoArr.photoPtrs[i]);
    }
}

PhotoArray::~PhotoArray() {
    for(int i = 0; i < numPhotos; ++i){
        delete photoPtrs[i];
    }
    delete [] photoPtrs;
}

bool PhotoArray::isFull() const{
    return size() == MAX_ARRAY;
}

bool PhotoArray::add(Photo *photo){
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

Photo *PhotoArray::get(int index) const{
    if(index < 0 || index > size()){
        return nullptr;
    }
    return photoPtrs[index];
}

Photo *PhotoArray::get(string title) const{
    for(int i = 0; i < size(); ++i){
        if(photoPtrs[i]->getTitle() == title){
            return get(i);
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


Photo *PhotoArray::remove(string title) {
    for(int i = 0; i < size(); ++i){
        if(photoPtrs[i]->getTitle() == title){
            return remove(i);
        }
    }
    return nullptr;
}


int PhotoArray::size() const{
    return numPhotos;
}

void PhotoArray::display() const{
    for(int i = 0; i < numPhotos; ++i){
        photoPtrs[i]->display();
    }
}
