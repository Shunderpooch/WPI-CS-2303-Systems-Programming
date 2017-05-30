##Start of Makefile
make: main clean

main: main.o FCFS.o nodeOperations.o RoundRobin.o
	gcc -o Program3 main.o FCFS.o nodeOperations.o RoundRobin.o -lm

main.o: main.c globals.h
	gcc -Wall -c main.c -std=c99

FCFS.o: FCFS.c globals.h
	gcc -Wall -c FCFS.c -std=c99

nodeOperations.o: nodeOperations.c globals.h
	gcc -Wall -c nodeOperations.c -std=c99

RoundRobin.o: RoundRobin.c globals.h
	gcc -Wall -c RoundRobin.c -std=c99

clean: 
	rm *.o

##End of Makefile