#include "Photo.h"


using namespace std;

Photo::Photo(const string &photoTitle, const Date &date, const string &photoContent) {
    title = photoTitle;
    createdAt = date;
    content = photoContent;
}

bool Photo::equals(string photoTitle) {
    if(photoTitle == title ){
        return true;
    }
    return false;
}

void Photo::print() {
    cout<<"The name of this photo is "<<title<<"and it was created on "<<;
    createdAt.print();
}

void Photo::display() {
    print();
    cout<<content<<endl;
}