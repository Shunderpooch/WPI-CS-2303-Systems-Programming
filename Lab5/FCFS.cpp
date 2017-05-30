//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "globals.h"
#include "nodeOperations.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

//Run the first come, first serve quene.
FCFS::FCFS(int aPropogationTime, int aTransmissionTime, string aName){
	propogationTime = aPropogationTime;
	transmissionTime = aTransmissionTime;
	cTT = aTransmissionTime;
	name = aName;
}
//Simulates propogation, or the movement from one quene to the other, for a transmitted event quene/
void FCFS::propogationSimulation(FCFS **next, int simTime){
	//traverses sProcPtr and decrements the propogation time by one for each. Removes the first from the propogation quene 
	if(propogationQuene.decrementTime() == true){
		Link thisNode = propogationQuene.getNextEvent();
		if ((*next)->getPropogationTime() == -1){
			(*((Receiver**)next))->addEventReceiverSpecial(thisNode);
			return;
		}
		(*next)->addEvent(thisNode);
	}
}
//Adds an event to the event Transmission Quene
void FCFS::addEvent(Link thisNode){
	thisNode->setPropogationTime(propogationTime);
	if (DEBUG){
		cout << name << " has received packet " << thisNode->getPacketID() << endl;
	}
	transmissionQuene.bringToBack(thisNode);
}
//Gets the Transmission Time from 
int FCFS::getTransmissionTime(){
	return transmissionTime;
}
//Gets the Propogation Time
int FCFS::getPropogationTime(){
	return propogationTime;
}
//Gets the current Transmission Time
int FCFS::getCTT(){
	return cTT;
}
//Sets the current Transmission Time
void FCFS::setCTT(int newCTT){
	cTT = newCTT;
}
//Gets the name of the FCFS object.
string FCFS::getName(){
	return name;
}
//Gets the TransmissionQuene for FCFS
nodeOperations FCFS::getTransmissionQuene(){
	return transmissionQuene;
}
//Gets the PropogationQuene for FCFS
nodeOperations FCFS::getPropogationQuene(){
	return propogationQuene;
}
//Gets the Next event in the Transmission Quene
Link FCFS::getNextInTQ(){
	return transmissionQuene.getNextEvent();
}
//Sends an event to the Transmission Quene
void FCFS::sendToTQ(Link thisNode){
	transmissionQuene.bringToBack(thisNode);
}
//Sends an event to the Propogation Quene
void FCFS::sendToPQ(Link thisNode){
	propogationQuene.bringToBack(thisNode);
}
