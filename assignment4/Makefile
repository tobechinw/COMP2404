objects = Date.o main.o View.o AlbumCreator.o PhotoGram.o MediaFactory.o Criteria.o Album.o Photo.o

a4: $(objects)
	g++ -g -o a4 $(objects) && clear

main.o: main.cc Array.h
	g++ -c main.cc

View.o: View.h View.cc
	g++ -c View.cc

AlbumCreator.o: AlbumCreator.h AlbumCreator.cc Array.h
	g++ -c AlbumCreator.cc

PhotoGram.o: PhotoGram.h PhotoGram.cc Array.h
	g++ -c PhotoGram.cc

MediaFactory.o: MediaFactory.h MediaFactory.cc
	g++ -c MediaFactory.cc

Criteria.o: Criteria.cc Criteria.h
	g++ -c Criteria.cc

Album.o: Album.cc Album.h
	g++ -c Album.cc

Photo.o: Photo.cc Photo.h
	g++ -c Photo.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f a4 *.o && clear