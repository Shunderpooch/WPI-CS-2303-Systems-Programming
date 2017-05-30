##Author Arthur Dooner, CS2303, Lab 5, Section C02
##Start of Makefile

make: main clean

main: main.o Node.o nodeOperations.o FCFS.o Sender.o Mule.o Receiver.o
	g++ main.o Node.o nodeOperations.o FCFS.o Sender.o Mule.o Receiver.o -o Lab5

main.o: main.cpp FCFS.h Node.h nodeOperations.h
	g++ -Wall -c main.cpp -std=c++98

Node.o: Node.cpp Node.h
	g++ -Wall -c Node.cpp -std=c++98

nodeOperations.o: nodeOperations.cpp nodeOperations.h Node.h
	g++ -Wall -c nodeOperations.cpp -std=c++98

FCFS.o: FCFS.cpp FCFS.h Node.h
	g++ -Wall -c FCFS.cpp -std=c++98

Sender.o: Sender.cpp FCFS.h Node.h
	g++ -Wall -c Sender.cpp -std=c++98

Mule.o: Mule.cpp FCFS.h Node.h
	g++ -Wall -c Mule.cpp -std=c++98

Receiver.o: Receiver.cpp FCFS.h Node.h
	g++ -Wall -c Receiver.cpp -std=c++98
clean: 
	rm *.o

##End of Makefile
