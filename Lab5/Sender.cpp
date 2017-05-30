//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "globals.h"
#include "nodeOperations.h"
#include "Node.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void Sender::runner(FCFS **sendTo, int simTime){
	//Runs while the list is not empty
	//We know that Lab5 and Program5 both use simulation times of 1 sim. However, transmission time varies.
	if(getTransmissionQuene().getLength() != 0){
		if(DEBUG){
			printf("The sender is about to work on a packet at time %d.\n", simTime);
			cout << getName() << endl;
		}
		//we decrement the current transmissionTime
		setCTT(getCTT() - 1);
		//if the current transmission time is 0, bring to the back of the simulated propogation
		if(getCTT() == 0){
			Link tempPtr = getNextInTQ();
			tempPtr->setSender(getName()); /* As this is the sender quene, we're going to push the sender name to the packet. */
			tempPtr->setPropogationTime(getPropogationTime()+1); 
			sendToPQ(tempPtr);
			if (DEBUG){
				cout << "Moving " << tempPtr->getPacketID() <<" to Propogation Quene" << endl;
			}
			propogationSimulation(sendTo, simTime);
			/*This is where it needs to add things to the event list dynamically*/
			addFromFile("packetIDs", simTime);
			setCTT(getTransmissionTime());
		}
		//We have not reached the end of transmission.
		else if (getTransmissionQuene().getLength() != 0){
			propogationSimulation(sendTo, simTime);
		}
		//only transmitting in the last case, whereupon nothing is done.
	}
	//Everything has been transmitted from the Sender, but not everything has yet arrived at the Mule/Receiver
	else if(getPropogationQuene().getLength() != 0){
			propogationSimulation(sendTo, simTime);	
	}
	//The sender has no more packets to send. It sits idle for the remainder of the simulation.
}

//Takes in a base filename and takes the packet from the list in the file, then adds it to the LinkedList of events.
void Sender::addFromFile(string fileName, int simTime){
	static long positionAlongFile;
	static int numberAdded;
	static int numberAddedS1;
	static int numberAddedS2;
	if (numberAddedS1 == AMOUNTFROMEACH && getName() == "S1"){
		return;
	}
	if (numberAdded != (AMOUNTFROMEACH*2)){
		FILE *thisFile;
		int aPacketID;
		thisFile = fopen((fileName + ".txt").c_str(), "r");
		if(thisFile != NULL){
			fseek(thisFile, positionAlongFile, SEEK_SET);
			fscanf(thisFile, "%d", &aPacketID);
			positionAlongFile = ftell(thisFile);
			fclose(thisFile);
			if (DEBUG){
				printf("Adding packet %d from ", aPacketID);
				cout << getName() << endl;
			}
			Link aNode = new Node(aPacketID, simTime);
			sendToTQ(aNode);
			if (getName() == "S1"){
				numberAddedS1++;
			}
			else {
				numberAddedS2++;
			}
			numberAdded++;
		}
		else{
			printf("Error opening file\n");
		}
	}
}
