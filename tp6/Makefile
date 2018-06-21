all: monprog.out

monprog.out: main.o Liste.o ElementL.o
	g++ -g main.o Liste.o ElementL.o -o monprog.out

main.o: main.cpp Liste.h ElementL.h
	g++ -g -Wall -c main.cpp

Liste.o: Liste.h Liste.cpp ElementL.h
	g++ -g -Wall -c Liste.cpp

ElementL.o: ElementL.h ElementL.cpp
	g++ -g -Wall -c ElementL.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out
