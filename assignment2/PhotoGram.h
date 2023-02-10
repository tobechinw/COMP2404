#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include "Album.h"

class PhotoGram{
    public:
        bool addAlbum(string title, string description);
        bool addPhoto(string albumTitle, Photo photo);
        void removeAlbum(string albumTitle);
        void removePhoto(string albumTitle, string photoTitle);

        void downloadAlbum(string albumTitle);
        void downloadPhoto(string albumTitle, string photoTitle);
        void printAlbums();
        void displayAlbums();

};







#endif