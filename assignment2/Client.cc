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
        if( !albumArray->add(album) ){
            cout<<"Album could not be added"<<endl;
            return false;
        }
        return true;
    }
    cout<<"Album could not be found in PhotoGram"<<endl;
    return false;
}

bool Client::displayOnlinePhoto(PhotoGram *source, string albumTitle, string photoTitle) const{
    Album* album = source->downloadAlbum(albumTitle);
    if(album != nullptr){
        Photo* photo = album->getPhoto(photoTitle);
        if(photo!= nullptr){
            photo->display();
            return true;
        }
        cout<<"Photo could not be found"<<endl;
        return false;
    }
    cout<<"Album could not be found in PhotoGram"<<endl;
    return false;
}

bool Client::displayLocalPhoto(string albumTitle, string photoTitle) const{
    Album* album = albumArray->get(albumTitle);
    if(album != nullptr){
        Photo* photo = album->getPhoto(photoTitle);
        if(photo != nullptr){
            photo->display();
            return true;
        }
        cout<<"Photo could not be found"<<endl;
    }
    cout<<"Album could not be found"<<endl;
    return false;
}

void Client::printLocalAlbums() const{
    for(int i = 0; i < albumArray->size(); ++i){
        Album* album = albumArray->get(i);
        if(album!= nullptr){
            album->print();
        }
    }
}

void Client::displayLocalAlbums() const{
    for(int i = 0; i < albumArray->size(); ++i){
        Album *album = albumArray->get(i);
        if(album != nullptr){
            album->display();
        }
    }
}