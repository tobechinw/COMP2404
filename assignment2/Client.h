#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "PhotoGram.h"

using namespace std;

class Client{
    public:
        bool downloadAlbum(PhotoGram*, string);
        bool displayOnlinePhoto(PhotoGram*, string, string);
        bool displayLocalPhoto(string, string);
        void printLocalAlbums();
        void displayLocalAlbums();
};





#endif