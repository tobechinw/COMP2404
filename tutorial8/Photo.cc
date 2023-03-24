#include "Photo.h"
//#include "Date.h"


using namespace std;

Photo::Photo(const string &photoTitle, const string& category, const Date &date, const string &content): title(photoTitle), category(category), createdAt(new Date(date)), photoContent(content){}

Photo::Photo(): title("tobechi's photo"), category("A"), createdAt(new Date(2023,1,1)), photoContent("RCMP Violation") {}

Photo::~Photo(){
    delete createdAt;
}

Photo::Photo(const Photo& photo): title(photo.title), createdAt(new Date(*photo.createdAt)) {
    photoContent = photo.photoContent ;
}

bool Photo::equals(string photoTitle) const{
    if(photoTitle == title){
        return true;
    }
    return false;
}

void Photo::print(ostream& os) const{
    os<<"The name of this photo is "<<title<<" and it was created on ";
    createdAt->print(os);
}


void Photo::display(ostream& os) const{
    print(os);
    os<<photoContent<<endl;
}

string Photo::getTitle() const{
    return title;
}

const string& Photo::getCategory() const {
    return category;
}

const Date& Photo::getDate() const {
    return *createdAt;
}

ostream& operator<<(ostream& os, const Photo& photo){
    photo.print(os);
    return os;
}