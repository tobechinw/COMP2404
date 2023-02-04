all: a1 Hotel.o Room.o Reservation.o Date.o

a1: Hotel.o Room.o Reservation.o Date.o main.cc
	g++ -o a1 Hotel.o Room.o Reservation.o Date.o main.cc

Hotel.o: Hotel.cc Hotel.h Room.h Reservation.h
	g++ -c Hotel.cc

Room.o: Room.cc Room.h defs.h Reservation.h
	g++ -c Room.cc

Reservation.o: Reservation.h Reservation.cc Date.h defs.h
	g++ -c Reservation.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f *.o a1