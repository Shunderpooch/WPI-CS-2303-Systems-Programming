Author: 					Arthur Dooner
							Project Partner
							Readme originally attempted by Project Partner, did
							not describe enough, rewritten by Arthur Dooner
							H2
Date:						March 6th, 2014 
Version:					1.00
CS Class:					CS 2303 Section C02
Programming Language:		C++ (C++ 98)
OS/Hardware Dependencies:	Requires anything with g++

Problem Description:		In this program, we were required to simulate a 
							packet transfer simulation (MANET packets) across
							a network with moving nodes, and static senders and
							receivers. It was needed to take in the amount of
							senders, mules, and receivers, and the board size
							in order to randomly place those items on the board
							and allow them to start sending and receiving 
							packets. With the given testdata, the program adds
							sources with the given properties and path along
							the grid, with the source building packets and 
							sending them. 
							To transfer a packet, it uses a distance function
							dependent on how far away the packets are from each
							other to be propogated. It is transmitted through a
							packet in a FCFS queue based on its size. When a 
							packet reaches a receiver, it stops moving. When
							the simulation is complete, the ending calculations
							for the receivers are recorded.

Interfaces:
	User					The User inputs to the function ./manetsim SOURCES
							RECEIVERS MULES DIMENSIONOFGRID
	Data					Reads from the file "prog5.txt" SOURCES lines of
							input to build the sender FCFS queues.

Implementation Details: 
	Data					-Sets of FCFS queues inherited in each node.
							-One graph function that holds a two-dimensional
							vector of ints and the one dimensional one of all 
							FCFS queues.
							-Packet Data structures with their attributes.
							-FCFS objects that hold everything 

How to build the Program:	make
							make builds the entire program for you.

How to run the Program: 	./manetsim SOURCES RECEIVERS MULES DIMENSION
	specifically			./manetsim 20 12 16 36.

Program Source:				FCFS.cpp
							FCFS.h
							globals.h
							Graph.cpp
							Graph.h
							main.cpp
							Makefile
							Mule.cpp
							Packet.cpp
							Packet.h
							packetQueue.cpp
							packetQueue.h
							Receiver.cpp
							Sender.cpp

Other Files:				output.txt, example of the program running
							prog5.txt, the test data.
							README.txt, this file.

