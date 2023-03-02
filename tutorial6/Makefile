all: test
	
test: test.cc Queue.o Order.o Location.o
	g++ -o test test.cc Queue.o Order.o Location.o
	
Queue.o:	Queue.h Queue.cc Order.h
	g++ -c Queue.cc 

Order.o:	Order.h Order.cc Location.h
	g++ -c Order.cc

Location.o:	Location.h Location.cc
	g++ -c Location.cc 
	
clean:
	rm -f test *.o
