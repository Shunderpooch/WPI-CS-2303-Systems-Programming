//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "globals.h"
#include "packetQueue.h"
#include "Packet.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//Gets the size of the Receiver Queue.
int Receiver::getSize(){
	return getTransmissionQueue().getLength();
}
void Receiver::buildVectors(int numSenders){
	receivedItems.resize(numSenders);
	while (getSize() != 0){
		Link tempPtr = getNextInTQ(); 
		numPackets++;
		if (receivedItems[(tempPtr->getSender() - 1)].size() != 0){
			receivedItems[(tempPtr->getSender() - 1)].push_back(tempPtr);
		}
		else{
			vector<Link> tempVector;
			tempVector.push_back(tempPtr);
			receivedItems[(tempPtr->getSender() - 1)] = tempVector;
		}
	}
}
//Prints the average times from both event Queues. 
void Receiver::printCalculations(){
	vector<double> averages;
	int superTotal;
	cout << getID() << ", a receiver, has received a total of " << numPackets << " Packets." << endl;
	//Traverse the received items vector
	for (unsigned int x = 0; x < receivedItems.size(); x++){
		int total = 0;
		int numPacketsFromSource = 0;
		//Traverse the individual sources 
		for(unsigned int y = 0; y < receivedItems[x].size(); y++){
			total += receivedItems[x][y]->getResponseTime();
			numPacketsFromSource++;
		}
		superTotal += total;
		//Check To make sure we should actually print out something 
		if (numPacketsFromSource != 0){
			cout << getID() << " has received a total of " << numPacketsFromSource << " from sender " << (x+1) << ", with an average response time of " << ((double)total)/numPacketsFromSource << " sims." << endl; 
			averages.push_back(((double)total)/numPacketsFromSource);
		}
	}
	
	cout << "The average response time for all packets to " << getID() << " is " << ((double)superTotal)/numPackets << " sims." << endl;
}
