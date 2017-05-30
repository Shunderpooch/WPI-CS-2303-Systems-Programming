//Author Arthur Dooner, CS2303, Program 5
#include "FCFS.h"
#include "globals.h"
#include "Packet.h"
#include "packetQueue.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Run the first come, first serve Queue.
FCFS::FCFS(int anID, int anArrivalTime){
	ID = anID;
	arrivalTime = anArrivalTime;
	cTT = 0;
}
//Simulates propogation, or the movement from one Queue to the other, for a transmitted event Queue/
void FCFS::propogationSimulation(vector<FCFS*> **items, int simTime){
	//traverses sProcPtr and decrements the propogation time by one for each. Also, removes all ending events and puts them into the vector allEnding.
	vector<Link> allEnding;
	allEnding = propogationQueue.decrementTime();
	if(allEnding.size() != 0){
		cout << "There are " << allEnding.size() << " items moving to their next location. They include: " << endl;
		for(unsigned int z = 0; z < allEnding.size(); z++){
			int theNextLocation = allEnding[z]->getNextLoc();
			cout << "      " << allEnding[z]->getPacketID() << ", which is moving to " << theNextLocation << endl;
			((**items)[(theNextLocation - 1)])->addEvent(allEnding[z]);
		}
		cout << endl;
		/*if ((*next)->getPropogationTime() == -1){
			(*((Receiver**)next))->addEventReceiverSpecial(thisNode);
			return;
		}
		(*next)->addEvent(thisNode);*/
	}  
}
//Adds an event to the event Transmission Queue
void FCFS::addEvent(Link thisNode){
	if (DEBUG){
		cout << ID << " has received packet " << thisNode->getPacketID() << endl;
	}
	transmissionQueue.bringToBack(thisNode);
}
//Gets the arrival Time
int FCFS::getArrivalTime(){
	return arrivalTime;
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
int FCFS::getID(){
	return ID;
}
//Gets the TransmissionQueue for FCFS
packetQueue FCFS::getTransmissionQueue(){
	return transmissionQueue;
}
//Gets the PropogationQueue for FCFS
packetQueue FCFS::getPropogationQueue(){
	return propogationQueue;
}
//Gets the Next event in the Transmission Queue
Link FCFS::getNextInTQ(){
	return transmissionQueue.getNextEvent();
}
//Sends an event to the Transmission Queue
void FCFS::sendToTQ(Link thisNode){
	cout << "Moving " << thisNode->getPacketID() << " to Transmission Queue." << endl; 
	transmissionQueue.bringToBack(thisNode);
}
//Sends an event to the Propogation Queue
void FCFS::sendToPQ(Link thisNode){
	cout << "Moving " << thisNode->getPacketID() << " to Propogation Queue." << endl; 
	propogationQueue.bringToBack(thisNode);
}
//Prints the name of the FCFS Queue.
void FCFS::printFCFS(){
	cout << ID;
}
//Gets the Location Y variable
int FCFS::getLocY(){
	return locY;
}
//Sets the Location Y and X variable
void FCFS::setLoc(int otherY, int otherX){
	locY = otherY;
	locX = otherX;
}
//Returns the Location X variable
int FCFS::getLocX(){
	return locX;
}
//Returns the direction of the FCFS object
DIRECTION FCFS::getDirection(){
	return dir;
}
//Sets the direction of the FCFS object
void FCFS::setDirection(DIRECTION aDir){
	dir = aDir;
}
//inverts Direction of the FCFS object
void FCFS::invertDirection(){
	switch(dir){
		case NORTH:
			dir = SOUTH;
			break;
		case SOUTH:
			dir = NORTH;
			break;
		case EAST:
			dir = WEST;
			break;
		case WEST:
			dir = EAST;
			break;
		case EMPTY:
			dir = EMPTY;
			break;
	}
}
//returns the distance
int FCFS::getDistanceFrom(int place, vector<FCFS*> **items){
	int otherX, otherY;
	otherX = (**items)[(place - 1)]->getLocX();
	otherY = (**items)[(place - 1)]->getLocY(); 
	double thisDistance = sqrt(pow(((double)locX-(double)otherX),2)+pow(((double)locY-otherY), 2));
	return ((int)(ceil(log10(thisDistance)/log10(2))));
}

