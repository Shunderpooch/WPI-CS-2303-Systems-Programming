//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "globals.h"
#include "packetQueue.h"
#include "Packet.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

//Runs through one sim of a sender activity, provided the simulation time and a pointer to all of the objects for the sender.
bool Sender::runner(vector<FCFS*> **items, int simTime){
	//Runs while the list is not empty
	//We know that Lab5 and Program5 both use simulation times of 1 sim. However, transmission time varies.
	int transmissionQueueLength = getTransmissionQueue().getLength();
	//Add packets if the queue is empty and there are still packets to be sent.
	if (transmissionQueueLength == 0){
		transmissionQueueLength += addPackets(simTime);
	}
	//Check to see if we have packets now.
	if(transmissionQueueLength != 0){
		cout << "Sender " << getID() << ":" << endl;
		if(DEBUG){
			cout << "Sender " << getID() << " is about to work on a packet at time " << simTime << endl;
		}
		//we decrement the current transmissionTime
		setCTT(getCTT() - 1);
		if (DEBUG){
			cout << "Current transmission time is " << getCTT() << endl;
		}
		//if the current transmission time is 0, bring to the back of the simulated propogation
		if(getCTT() <= 0){
			Link tempPtr = getNextInTQ();
			int nextInListToMove = tempPtr->getNextFCFS(); /*Gets the item where the packet is intended to move to.*/
			int distance = getDistanceFrom(nextInListToMove, items);
			tempPtr->setNextLoc(nextInListToMove);
			if(DEBUG){
				cout << tempPtr->getPacketID() << " has distance from its objective " << nextInListToMove << " " << distance << endl;
			}
			tempPtr->setPropogationTime(distance + 1); 
			tempPtr->setFinishTime(simTime + distance);
			sendToPQ(tempPtr);
			if (DEBUG){
				cout << "Moving " << tempPtr->getPacketID() <<" to Propogation Queue" << endl;
			}
			propogationSimulation(items, simTime);
		}
		//We have not reached the end of transmission.
		else if (getTransmissionQueue().getLength() != 0){
			propogationSimulation(items, simTime);
		}
		//only transmitting in the last case, whereupon nothing is done.
	}
	//Everything has been transmitted from the Sender, but not everything has yet arrived at the Mule/Receiver
	else if(getPropogationQueue().getLength() != 0){
			propogationSimulation(items, simTime);	
	}
	//The sender has no more packets to send. It sits idle for the remainder of the simulation.
	else {
		return false;
	}
	return true;
}
//Adds packets to the Sender to send
int Sender::addPackets(int simTime){
	if (numPackets > counter){
		Packet *aPacket = new Packet(((getID() * 1000) + counter), (simTime + packetSize), packetSize, SR);
		counter++;
		if (DEBUG){
			cout << "Packet " << aPacket->getPacketID() << " has been created in sender " << getID() << " at time " << simTime << " sims." << endl << endl; 
			aPacket->printSR();
		}
		sendToTQ(aPacket);
		setCTT(packetSize);
		return 1;
	}
	return 0;
}

