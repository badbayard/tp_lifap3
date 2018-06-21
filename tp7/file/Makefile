all: monprog.out

monprog.out: main.o Liste.o ElementL.o File.o
	g++ -g main.o Liste.o ElementL.o File.o

main.o: main.cpp Liste.h ElementL.h File.h Liste.h
	g++ -g -Wall -c main.cpp

Liste.o: Liste.h Liste.cpp
	g++ -g -Wall -c Liste.cpp

ElementL.o: ElementL.h ElementL.cpp
	g++ -g -Wall -c ElementL.cpp

File.o: File.h File.cpp
	g++ -g -Wall -c File.cpp

clean:
	rm *.out

veryclean:clean
	rm *.out
