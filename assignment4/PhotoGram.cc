#include "PhotoGram.h"
using namespace std;

PhotoGram::~PhotoGram() {
    for(int i = 0; i < photoArray.size(); ++i){
        delete photoArray[i];
    }

    for(int i = 0; i < albumArray.size(); ++i){
        delete albumArray[i];
    }
}

void PhotoGram::addAlbum(string albumTitle, string description) {
    Album* album = mediaFactory.createAlbum(albumTitle, description);
    albumArray+=album;
}

void PhotoGram::addToAlbum(int index, Array<Photo *> photoArr) {
    if(index < 0 || index > photoArray.size()){
        cerr<<"Invalid index"<<endl;
        exit(1);
    }

    for(int i = 0; i < photoArr.size(); ++i){
        albumArray[index]->addPhoto(photoArr[i]);
    }
}

void PhotoGram::uploadPhoto(const string &title) {
    Photo* photo = mediaFactory.uploadPhoto(title);
    photoArray+=photo;
}

void PhotoGram::deleteAlbum(int index) {
    if(index > albumArray.size() || index < 0){
        cerr<<"Invalid index"<<endl;
        exit(1);
    }
    albumArray-=albumArray[index];
}

void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo *>& photoArr) const{
    for(int i = 0; i < photoArray.size(); ++i){
        if(criteria.matches(*photoArray[i])){
            photoArr+=photoArray[i];
        }
    }
}

void PhotoGram::displayAlbum(int index, View &view) {
    if(index < 0 || index > albumArray.size()){
        cerr<<"Invalid index"<<endl;
    }

    view.displayAlbum(*albumArray[index]);
}

int PhotoGram::printAlbums(View &view) {
    view.printAlbums(albumArray);
    return albumArray.size();
}

void PhotoGram::displayPhoto(int index, View & view) {
    if(index < 0 || index > photoArray.size()){
        cerr<<"Invalid index"<<endl;
    }

    view.displayPhoto(*photoArray[index]);
}

int PhotoGram::printPhotos(View &view) {
    view.printPhotos(photoArray);
    return photoArray.size();
}