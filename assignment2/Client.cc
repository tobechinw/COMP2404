#include "Client.h"


Client::Client() {
    albumArray = new AlbumArray();
}

Client::~Client() {
    delete albumArray;
}

bool Client::downloadAlbum(PhotoGram *source, string title) {
    Album* album = source->downloadAlbum(title);
    if(album != nullptr){
        return albumArray->add(album);
    }
    return false;
}

bool Client::displayOnlinePhoto(PhotoGram *source, string albumTitle, string photoTitle) {
    Album* album = source->downloadAlbum(albumTitle);
    if(album != nullptr){
        Photo* photo = album->getPhoto(photoTitle);
        if(photo!= nullptr){
            photo->display();
            return true;
        }
    }
    return false;
}

bool Client::displayLocalPhoto(string albumTitle, string photoTitle) {
    Album* album = albumArray->get(albumTitle);
    if(album != nullptr){
        Photo* photo = album->getPhoto(photoTitle);
        if(photo != nullptr){
            photo->display();
            return true;
        }
    }
    return false;
}

void Client::printLocalAlbums() {
    for(int i = 0; i < albumArray->size(); ++i){
        Album* album = albumArray->get(i);
        if(album!= nullptr){
            album->print();
        }
    }
}

void Client::displayLocalAlbums() {
    for(int i = 0; i < albumArray->size(); ++i){
        Album *album = albumArray->get(i);
        if(album != nullptr){
            album->display();
        }
    }
}