#include "Album.h"

using namespace std;


Album::Album(const string &title, const string &description): title(title), description(description) {}

Album::~Album() {
    cout<<"Album d'tor"<<endl;
}

string Album::getTitle() const{
    return title;
}

bool Album::equals(string albumTitle) const{
    return title == albumTitle;
}

void Album::addPhoto(Photo* photo) {
    photoArray.add(photo);
}

Photo *Album::getPhoto(int index) const{
    return photoArray[index];
}

void Album::print(ostream& os) const{
    os<<"Album title is "<<title<<" and description is "<<description<<endl;
}

void Album::display(ostream& os) const{
    print(os);
    for(int i = 0; i < photoArray.size(); ++i){
        photoArray[i]->display(os);
    }
}

int Album::size() const{
    return photoArray.size();
}


ostream& operator<<(ostream& os, const Album & album){
    album.print(os);
    return os;
}

