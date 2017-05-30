//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "globals.h"
#include "nodeOperations.h"
#include "Node.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
//Adds an event to the receiving eventQuene.
void Receiver::addEventReceiverSpecial(Link thisNode){
	thisNode->setPropogationTime(getPropogationTime());
	if (thisNode->getSender() == "S1"){
		thisNode->printNode();
		allTimesS1.push_back(thisNode->getResponseTime());
	}
	else if (thisNode->getSender() == "S2"){
		thisNode->printNode();
		allTimesS2.push_back(thisNode->getResponseTime());
	}
	else {
		cout << "Something went wrong" << endl;
	}
	sendToTQ(thisNode);
}
//Gets the size of the Receiver Quene.
int Receiver::getSize(){
	return getTransmissionQuene().getLength();
}
//Prints the average times from both event quenes. 
void Receiver::printAverageTimes(){
	int Total = 0;
	double average1, average2;
	for (unsigned int x = 0; x < allTimesS1.size(); x++){
		Total += allTimesS1[x];
	}
	average1 = (double)Total/(allTimesS1.size());
	Total = 0;
	for (unsigned int y = 0; y < allTimesS1.size(); y++){
		Total += allTimesS2[y];
	}
	average2 = (double)Total/(allTimesS2.size());
	cout << "The average time for packets from S1 is " << average1 << " sims, and the average time for packets from S2 is " << average2 << " sims." << endl;
}
