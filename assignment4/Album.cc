#include "Album.h"

using namespace std;

Album::Album(const string &title, const string &description) : title(title), description(description), photoArray(new PhotoArray()) {}


Album::Album(const Album &album): title(album.title), description(album.description) {
    photoArray = new PhotoArray(* album.photoArray);
}


Album::~Album() {
    delete photoArray;
}

string Album::getTitle() const{
    return title;
}

bool Album::equals(string albumTitle) const{
    return title == albumTitle;
}

bool Album::lessThan(Album &alb) const{
    return title < alb.title;
}

bool Album::addPhoto(Photo* photo) {
    return photoArray->add(photo);
}

bool Album::addPhoto(int index, Photo *photo) {
    return photoArray->add(index, photo);
}

Photo *Album::getPhoto(int index) const{
    return photoArray->get(index);
}

Photo *Album::getPhoto(string title) const{
    return photoArray->get(title);
}

Photo *Album::removePhoto(string songTitle) {
    return photoArray->remove(songTitle);
}

Photo *Album::removePhoto(int index) {
    return photoArray->remove(index);
}

void Album::print() const{
    cout<<"Album title is "<<title<<" and description is "<<description<<endl;
}

void Album::display() const{
    print();
    photoArray->display();
}

int Album::size() const{
    return photoArray->size();
}