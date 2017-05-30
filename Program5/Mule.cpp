//Author Arthur Dooner, CS2303, Program 5
#include "FCFS.h"
#include "globals.h"
#include "packetQueue.h"
#include "Packet.h"
#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

bool Mule::runner(vector<FCFS*> **items, int simTime){
	//Runs while the list is not empty
	//We know that Lab5 and Program5 both use simulation times of 1 sim. However, transmission time varies.
	int length = getTransmissionQueue().getLength();
	if(length != 0){
		cout << "Mule " << getID() << endl;
		//Check to make sure we're not waking up after a period of being completed with sending things
		if(getCTT() <= 0){
			if (getTransmissionQueue().getFirstFinish() == simTime){
				return true;
			}
			setCTT(getTransmissionQueue().getFirstSize());
		}
		if(DEBUG){
			cout << getID() << " is working on packet " << endl;
		}
		//we decrement the current transmissionTime
		setCTT(getCTT() - 1);
		if (DEBUG){
			cout << "Current transmission time is " << getCTT() << endl;
		}
		//if the current transmission time is 0, bring to the back of the simulated propogation
		if(getCTT() == 0){
			Link tempPtr = getNextInTQ();
			int nextInListToMove = tempPtr->getNextFCFS();
			if(nextInListToMove == getID()){
				cout << "WARNING" << endl;
			}
			int distance = getDistanceFrom(nextInListToMove, items);
			tempPtr->setPropogationTime(distance + 1);
			tempPtr->setFinishTime(simTime + distance + 1);
			tempPtr->setNextLoc(nextInListToMove);
			if (DEBUG){
				cout << "Moving " << tempPtr->getPacketID() << " to Propogation Queue of " << getID() << endl;
			}
			sendToPQ(tempPtr);
			propogationSimulation(items, simTime);
			if (getTransmissionQueue().getLength() != 0){
				setCTT(getTransmissionQueue().getFirstSize());
			}
			if (DEBUG){
				cout << "Completed a cycle of " << getID() << " transferring a node to the propogation queue." << endl;
			}
			return true;
		}
		else if (getPropogationQueue().getLength() != 0){
			propogationSimulation(items, simTime);
			if (DEBUG){
				cout << "Completed a cycle of " << getID() << " decrementing the transmission time and running the propogation queue." << endl;
			}
			return true;
		}
		else{
			return true;
		}
	}
	//Everything has been transmitted from the Sender/Mule, but not everything has yet arrived at the Mule/Receiver
	else if(getPropogationQueue().getLength() != 0){
			cout << "Mule " << getID() << endl;
			propogationSimulation(items, simTime);
			if (DEBUG){
				cout << "Completed a cycle of " << getID() << " running the propogation queue." << endl;
			}
			return true;
	}
	return false;
	//The sender has no more packets to send, or has not received/currently working on any packets.
}
