#include "Photo.h"


using namespace std;

Photo::Photo(const string &photoTitle, const Date &date, const string &content): title(photoTitle), createdAt(date), photoContent(content){}

Photo::Photo(): title("tobechi's photo"), createdAt(), photoContent("RCMP Violation") {}

Photo::Photo(Photo& photo): title(photo.title), createdAt(photo.createdAt) {
    photoContent = photo.photoContent + "RCMP violation for content";
}

bool Photo::equals(string photoTitle) {
    if(photoTitle == title ){
        return true;
    }
    return false;
}

void Photo::print(){
    cout<<"The name of this photo is "<<title<<" and it was created on ";
    createdAt.print();
}


void Photo::display(){
    print();
    cout<<photoContent<<endl;
}