#include "PhotoGram.h"
using namespace std;


//class PhotoGram{
//private:
//    Array<Album*> albumArray;
//    Array<Photo*> photoArray;
//    MediaFactory* mediaFactory;
//public:
//    PhotoGram();
//    ~PhotoGram();
//    bool addAlbum(string albumTitle, string description);
//    void addToAlbum(Array<Photo*> photoArray, int index);
//    void uploadPhoto(const string& title);
//    void deleteAlbum(int index);
//    void getPhotos(Criteria* criteria, Array<Photo*>);
//    void displayAlbum(int index, View&);
//    int printAlbums(View&);
//    void displayPhoto(int index, View&);
//    int printPhotos(View&);
//};



//PhotoGram::PhotoGram() {
//    mediaFactory = new MediaFactory()
//
//    albumArray = new AlbumArray();
//}

//PhotoGram::~PhotoGram() {
//    delete albumArray;
//}

void PhotoGram::addAlbum(string albumTitle, string description) {
    Album* album = mediaFactory->createAlbum(albumTitle, description);
    albumArray.add(album);
}

void PhotoGram::addToAlbum(int index, Array<Photo *> photoArr) {
    if(index > albumArray.size() || index < 0){
        cerr<<"Invalid index"<<endl;
    }

    for(int i = 0; i < photoArr.size(); ++i){
        albumArray[index]->addPhoto(photoArr[i]);
    }
}

void PhotoGram::uploadPhoto(const string &title) {
    Photo* photo = mediaFactory->uploadPhoto(title);
    photoArray.add(photo);
}

void PhotoGram::deleteAlbum(int index) {
    if(index > albumArray.size() || index < 0){
        cerr<<"Invalid index"<<endl;
    }

    albumArray.remove(albumArray[index]);
}

void PhotoGram::getPhotos(const Criteria& criteria, Array<Photo *>& photoArr) const{
    for(int i = 0; i < photoArr.size(); ++i){
        if(criteria.matches(*photoArr[i])){
            photoArr.add(photoArr[i]);
        }
    }
}

void PhotoGram::displayAlbum(int index, View &view) {
    if(index < 0 || index > albumArray.size()){
        cerr<<"Invalid index"<<endl;
    }

    view.displayAlbum(*albumArray[index]);
}

int PhotoGram::printAlbums(View &view) {
    view.printAlbums(albumArray);
    return albumArray.size();
}

void PhotoGram::displayPhoto(int index, View & view) {
    if(index < 0 || index > photoArray.size()){
        cerr<<"Invalid index"<<endl;
    }

    view.displayPhoto(*photoArray[index]);
}

int PhotoGram::printPhotos(View &view) {
    view.printPhotos(photoArray);
    return photoArray.size();
}