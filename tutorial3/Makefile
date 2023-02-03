all: test1 test2 Room.o Reservation.o Date.o

test1: Room.o Reservation.o Date.o test1.cc
	g++ -o test1 Room.o Reservation.o Date.o test1.cc

test2: Reservation.o Date.o
	g++ -o test2 Reservation.o Date.o test2.cc

Room.o: Room.cc Room.h defs.h Reservation.h
	g++ -c Room.cc

Reservation.o: Reservation.h Reservation.cc Date.h defs.h
	g++ -c Reservation.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f *.o p1