##Author Arthur Dooner, CS2303, Program 5, Section C02
##Start of Makefile

make: main clean

main: main.o Packet.o packetQueue.o FCFS.o Sender.o Mule.o Receiver.o Graph.o
	g++ main.o Packet.o packetQueue.o FCFS.o Sender.o Mule.o Receiver.o Graph.o -o manetsim

main.o: main.cpp FCFS.h Packet.h packetQueue.h
	g++ -Wall -c main.cpp -std=c++98

Packet.o: Packet.cpp Packet.h
	g++ -Wall -c Packet.cpp -std=c++98

packetQueue.o: packetQueue.cpp packetQueue.h Packet.h
	g++ -Wall -c packetQueue.cpp -std=c++98

FCFS.o: FCFS.cpp FCFS.h Packet.h
	g++ -Wall -c FCFS.cpp -std=c++98

Sender.o: Sender.cpp FCFS.h Packet.h
	g++ -Wall -c Sender.cpp -std=c++98

Mule.o: Mule.cpp FCFS.h Packet.h
	g++ -Wall -c Mule.cpp -std=c++98

Receiver.o: Receiver.cpp FCFS.h Packet.h
	g++ -Wall -c Receiver.cpp -std=c++98

Graph.o: Graph.cpp Graph.h FCFS.h
	g++ -Wall -c Graph.cpp -std=c++98

clean: 
	rm *.o

##End of Makefile
