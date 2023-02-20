all: a1

a1: PhotoArray.o Photo.o Album.o AlbumArray.o PhotoGram.o Client.o TestControl.o TestView.o Date.o main.cc
	g++ -o a1 PhotoArray.o Photo.o Album.o AlbumArray.o PhotoGram.o Client.o TestControl.o TestView.o Date.o main.cc

Photo.o: Photo.h Photo.cc
	g++ -c Photo.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h
	g++ -c PhotoArray.cc

Album.o: Album.cc Album.h
	g++ -c Album.cc

AlbumArray.o: AlbumArray.cc AlbumArray.h Album.o
	g++ -c AlbumArray.cc

PhotoGram.o: PhotoGram.cc PhotoGram.h
	g++ -c PhotoGram.cc

Client.o: Client.cc Client.h
	g++ -c Client.cc

TestControl.o: Photo.o Client.o
	g++ -c TestControl.cc

TestView.o: TestView.cc TestView.h
	g++ -c TestView.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

clean:
	rm -f *.o a1