#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H


#include "defs.h"
#include "AlbumArray.h"
#include <string>
#include <iostream>


class PhotoGram{
    private:
        AlbumArray *albumArray;
    public:
        PhotoGram();
        ~PhotoGram();
        bool addAlbum(string albumTitle, string description);
        bool removeAlbum(string albumTitle);
        bool addPhoto(string albumTitle, Photo photo);
        bool removePhoto(string albumTitle, string photoTitle);
        Album* downloadAlbum(string albumTitle) const;
        Photo* downloadPhoto(string albumTitle, string photoTitle) const;
        void printAlbums() const;
        void displayAlbums() const;
};


#endif