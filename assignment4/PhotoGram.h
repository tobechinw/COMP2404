#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H


#include "defs.h"
#include <string>
#include <iostream>
#include "Array.h"
#include "Album.h"
#include "Photo.h"
#include "MediaFactory.h"

#include "View.h"


class PhotoGram{
    private:
        Array<Album*> albumArray;
        Array<Photo*> photoArray;
        MediaFactory mediaFactory;
    public:
        ~PhotoGram();
        void addAlbum(string albumTitle, string description);
        void addToAlbum(int index, Array<Photo*> photoArray);
        void uploadPhoto(const string& title);
        void deleteAlbum(int index);
        void getPhotos(const Criteria& criteria, Array<Photo*>&) const;
        void displayAlbum(int index, View&);
        int printAlbums(View&);
        void displayPhoto(int index, View&);
        int printPhotos(View&);
};


#endif