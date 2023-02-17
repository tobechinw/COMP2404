#include "Album.h"

using namespace std;

Album::Album(const string &title, const string &description) : title(title), description(description) {
    photoArray = new PhotoArray();
}

Album::Album(const Album &album): title(album.title), description(album.description) {
    photoArray = new PhotoArray(* album.photoArray);
}


Album::~Album() {
    delete photoArray;
}

string Album::getTitle() {
    return title;
}

bool Album::equals(string albumTitle) {
    return title == albumTitle;
}

bool Album::lessThan(Album &alb) {
    return title < alb.title;
}

bool Album::addPhoto(Photo* photo) {
    return photoArray->add(photo);
}

bool Album::addPhoto(int index, Photo *photo) {
    return photoArray->add(index, photo);
}

Photo *Album::getPhoto(int index) {
    return photoArray->get(index);
}

Photo *Album::getPhoto(string title) {
    return photoArray->get(title);
}

Photo *Album::removePhoto(string songTitle) {
    return photoArray->remove(title);
}

Photo *Album::removePhoto(int index) {
    return photoArray->remove(index);
}

void Album::print() {
    cout<<"Album title is "<<title<<" and description is "<<description<<endl;
}

void Album::display() {
    print();
    photoArray->display();
}

int Album::size() {
    return photoArray->size();
}