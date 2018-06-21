all: monprog.out

monprog.out: main.o Arbre.o ElementA.o
	g++ -g main.o Arbre.o ElementA.o -o monprog.out

main.o: main.cpp Arbre.h ElementA.h
	g++ -g -Wall -c main.cpp

Arbre.o: Arbre.h Arbre.cpp ElementA.h
	g++ -g -Wall -c Arbre.cpp

ElementA.o: ElementA.h ElementA.cpp
	g++ -g -Wall -c ElementA.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out
