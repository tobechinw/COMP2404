#include "PhotoGram.h"
using namespace std;



PhotoGram::PhotoGram() {
    albumArray = new AlbumArray();
}

PhotoGram::~PhotoGram() {
    delete albumArray;
}

bool PhotoGram::addAlbum(string title, string description) {
    Album* album = new Album(title, description);
    if(!albumArray->add(album)){
        cout<<"Album could not be added"<<endl;
        delete album;
        return false;
    }
    return true;
}

bool PhotoGram::removeAlbum(string albumTitle){
    if(!albumArray->remove(albumTitle)){
        cout<<"Album could not be removed"<<endl;
        return false;
    }
    return true;
}

bool PhotoGram::addPhoto(string albumTitle, Photo photo) {
    Album* album = albumArray->get(albumTitle);
    if(album != nullptr){
        Photo* photo1 = new Photo(photo);
        if(!albumArray->get(albumTitle)->addPhoto(photo1)){
            cout<<"Photo could not be added"<<endl;
            delete photo1;
            return false;
        }
        return true;
    }
    cout<<"Album not found"<<endl;
    return false;
}

bool PhotoGram::removePhoto(string albumTitle, string photoTitle){
    Album* album = albumArray->get(albumTitle);
    if(album != nullptr){
        Photo* photo = albumArray->get(albumTitle)->removePhoto(photoTitle);
        if(photo != nullptr){
            return true;
        }else{
            cout<<"Photo could not be found"<<endl;
            return false;
        }
    }
    cout<<"Album could not be found"<<endl;
    return false;
}

Album* PhotoGram::downloadAlbum(string albumTitle) const{
    return albumArray->get(albumTitle);
}


Photo *PhotoGram::downloadPhoto(string albumTitle, string photoTitle) const{
    Album * album = albumArray->get(albumTitle);
    if(album != nullptr){
        return albumArray->get(albumTitle)->getPhoto(photoTitle);
    }
    return nullptr;
}

void PhotoGram::printAlbums() const{
    for(int i = 0; i < albumArray->size(); ++i){
        Album* album = albumArray->get(i);
        if(album!= nullptr){
            album->print();
        }
    }
}

void PhotoGram::displayAlbums() const{
    for(int i = 0; i < albumArray->size(); ++i){
        Album * album = albumArray->get(i);
        if(album != nullptr){
            album->display();
        }
    }
}