#include "Photo.h"
//#include "Date.h"


using namespace std;

Photo::Photo(const string &photoTitle, const Date &date, const string &content): title(photoTitle), createdAt(new Date(date)), photoContent(content){}

Photo::Photo(): title("tobechi's photo"), createdAt(new Date(2023,1,1)), photoContent("RCMP Violation") {}

Photo::Photo(Photo& photo): title(photo.title), createdAt(photo.createdAt) {
    photoContent = photo.photoContent ;
}

bool Photo::equals(string photoTitle) const{
    if(photoTitle == title ){
        return true;
    }
    return false;
}

void Photo::print() const{
    cout<<"The name of this photo is "<<title<<" and it was created on ";
    createdAt->print();
}


void Photo::display() const{
    print();
    cout<<photoContent<<endl;
}

string Photo::getTitle() const{
    return title;
}