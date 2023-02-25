#include "AlbumArray.h"
using namespace std;

AlbumArray::AlbumArray() {
    numAlbums = 0;
    albumArray = new Album*[MAX_ARRAY];
}

AlbumArray::~AlbumArray() {
    delete [] albumArray;
}

AlbumArray::AlbumArray(const AlbumArray &albumArr): numAlbums(albumArr.numAlbums) {
    albumArray = new Album*[MAX_ARRAY];
    for(int i = 0; i < numAlbums; ++i){
        albumArray[i] = new Album(*albumArr.albumArray[i]);
    }
}

bool AlbumArray::isFull() const{
    return numAlbums == MAX_ARRAY;
}

int AlbumArray::size() const{
    return numAlbums;
}

bool AlbumArray::add(Album *album) {
    if(isFull()){
        return false;
    }

    if(numAlbums == 0){
        albumArray[numAlbums] = album;
        numAlbums++;
        return true;
    }
    for(int i = 0; i < numAlbums; ++i){
        if(album->lessThan(*albumArray[i])){
            for(int j = numAlbums + 1; j > i; j --){
                albumArray[j] = albumArray[j-1];
            }
            albumArray[i] = album;
            numAlbums++;
            return true;
        }
    }
    albumArray[numAlbums] = album;
    numAlbums++;
    return true;
}


Album* AlbumArray::get(int index) const{
    if(index < 0 || index > size()){
        return nullptr;
    }
    return albumArray[index];
}

Album *AlbumArray::get(string title) const{
    for(int i = 0 ; i < numAlbums; ++i){
        if(albumArray[i]->equals(title)){
            return get(i);
        }
    }
    return nullptr;
}


Album *AlbumArray::remove(int index) {
    if(index < 0 || index > size()){
        return nullptr;
    }
    Album* album = albumArray[index];
    for(int i = index; i < numAlbums; ++i){
        albumArray[i] = albumArray[i+1];
    }
    numAlbums--;
    return album;
}

Album *AlbumArray::remove(string title){
    for(int i = 0; i < numAlbums; ++i){
        if(albumArray[i]->equals(title)){
            return remove(i);
        }
    }
    return nullptr;
}