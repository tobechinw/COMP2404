#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "PhotoGram.h"
#include "AlbumArray.h"

using namespace std;

class Client{
    private:
        AlbumArray *albumArray;
    public:
        Client();
        ~Client();
        bool downloadAlbum(PhotoGram* source, string title);
        bool displayOnlinePhoto(PhotoGram* source, string albumTitle, string photoTitle) const;
        bool displayLocalPhoto(string albumTitle, string photoTitle) const;
        void printLocalAlbums() const;
        void displayLocalAlbums() const;
};





#endif