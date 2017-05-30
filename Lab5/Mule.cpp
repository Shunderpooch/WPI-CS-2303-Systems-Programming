//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "globals.h"
#include "nodeOperations.h"
#include "Node.h"
#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int Mule::runner(FCFS **sendTo, int simTime){
	//Runs while the list is not empty
	//We know that Lab5 and Program5 both use simulation times of 1 sim. However, transmission time varies.
	int length = getTransmissionQuene().getLength();
	if(length != 0){
		if(DEBUG){
			cout << getName() << " is working on a packet." << endl;
		}
		//we decrement the current transmissionTime
		setCTT(getCTT()-1);
		//if the current transmission time is 0, bring to the back of the simulated propogation
		if(getCTT() == 0){
			Link tempPtr = getNextInTQ();
			tempPtr->setFinishTime((simTime + getPropogationTime()));
			tempPtr->setPropogationTime(getPropogationTime());
			sendToPQ(tempPtr);
			propogationSimulation(sendTo, simTime);
			setCTT(getTransmissionTime());
			return length - 1;
		}
		else if (getPropogationQuene().getLength() != 0){
			propogationSimulation(sendTo, simTime);
			return length;
		}
		else{
			return length;
		}
	}
	//Everything has been transmitted from the Sender/Mule, but not everything has yet arrived at the Mule/Receiver
	else if(getPropogationQuene().getLength() != 0){
			propogationSimulation(sendTo, simTime);	
			return 0;
	}
	return 0;
	//The sender has no more packets to send, or has not received/currently working on any packets.
}
