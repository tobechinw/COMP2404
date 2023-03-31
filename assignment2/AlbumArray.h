#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H
#include "defs.h"
#include "../assignment4/Album.h"


class AlbumArray{
    private:
        Album ** albumArray;
        int numAlbums;

    public:
        AlbumArray();
        ~AlbumArray();
        AlbumArray(const AlbumArray & albumArr);
        bool isFull() const;
        bool add(Album * album);
        Album * get(string title) const;
        Album * get(int index) const;
        Album * remove(string title);
        Album * remove(int index);
        int size() const;
};




#endif