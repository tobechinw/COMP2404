all: a2

a2: PhotoArray.o Photo.o Album.o AlbumArray.o PhotoGram.o Client.o TestControl.o TestView.o Date.o main.cc
	g++ -g -o a2 PhotoArray.o Photo.o Album.o AlbumArray.o PhotoGram.o Client.o TestControl.o TestView.o Date.o main.cc

Photo.o: ../assignment4/Photo.h ../assignment4/Photo.cc Date.o
	g++ -c Photo.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h Photo.o
	g++ -c PhotoArray.cc

Album.o: ../assignment4/Album.cc ../assignment4/Album.h Photo.o PhotoArray.o
	g++ -c Album.cc

AlbumArray.o: AlbumArray.cc AlbumArray.h Album.o
	g++ -c AlbumArray.cc

PhotoGram.o: PhotoGram.cc PhotoGram.h AlbumArray.o
	g++ -c PhotoGram.cc

Client.o: Client.cc Client.h PhotoGram.o AlbumArray.o
	g++ -c Client.cc

TestControl.o: Photo.o Client.o PhotoGram.o Client.o
	g++ -c TestControl.cc

TestView.o: TestView.cc TestView.h
	g++ -c TestView.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

clean:
	rm -f *.o a2