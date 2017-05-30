//Author Arthur Dooner, CS2303, Program 5
#include "Packet.h"
#include "globals.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//Creates a Packet from a packetID, and an arrivalTime.
Packet::Packet(int apacketID, int aTimeStamp, int size, vector<int> sourceRoute){
	packetID = apacketID;
	timeStamp = aTimeStamp;
	packetSize = size;
	SR = sourceRoute;
	sender = SR[0];
	SR.erase(SR.begin());
	next = NULL;
}
//Creates a Packet from a packetID, arrivalTime, and a link to the next one.
Packet::Packet(int apacketID, int aTimeStamp, int size, vector<int> sourceRoute, Link theNext){
	packetID = apacketID;
	timeStamp = aTimeStamp;
	packetSize = size;
	SR = sourceRoute;
	sender = SR[0];
	SR.erase(SR.begin());
	next = theNext;
}
//Gets the response time for a Packet
int Packet::getResponseTime(){
	return (finishTime - timeStamp);
}
//Gets the finish time for the packet.
int Packet::getFinishTime(){
	return finishTime;
}
//Sets the Finish Time at the specific FCFS Queue.
void Packet::setFinishTime(int aFinishTime){
	finishTime = aFinishTime;
}
//Gets the PacketID
int Packet::getPacketID(){
	return packetID;
}
//Gets the arrival time
int Packet::getArrivalTime(){
	return timeStamp;
}
//Gets the Link to the next Packet
Link Packet::getNext(){
	return next;
}
//Get the memory address of the next.
Link* Packet::getNextToAccess(){
	return &next;
}
//Sets the Link to the next Packet in the linkedList data structure 
void Packet::setNext(Link theNext){
	next = theNext;
}
//Sets the propogation time for the Packet.
void Packet::setPropogationTime(int aPropogationTime){
	propogationTime = aPropogationTime;
}
//Returns the propogation time for the Packet
int Packet::getPropogationTime(){
	return propogationTime;
}
//Gets the sender
int Packet::getSender(){
	return sender;
}
//Prints the Packet based on its information.
void Packet::printPacket(){
	cout << "The packet " << packetID << " was sent from " << sender << " and traversed the network in " << getResponseTime() << " seconds." << endl;
}
//Returnst the Source Route vector.
vector<int> Packet::getSR(){
	return SR;
}
//Prints the remaining source route.
void Packet::printSR(){
	for (unsigned int x = 0; x < SR.size(); x++){
		cout << SR[x] << " ";
	}
	cout << endl;
}
//Returns the integer representation of the next location to be sent to.
int Packet::getNextFCFS(){
	int nextItem = SR[0];
	SR.erase(SR.begin());
	return nextItem;
}
//Returns the size of the packet.
int Packet::getPacketSize(){
	return packetSize;
}
//Decrements the propogation times of every item it is linked to.
Link Packet::decrementItems(){
	propogationTime -= 1;
	if (DEBUG){
		cout << packetID << " is on the Propogation Queue and has a time of "<< propogationTime << endl;
	}
	if (next != NULL){
		next = next->decrementItems();
	}
	return this;
}
//Gets the next location from the packet.
int Packet::getNextLoc(){
	return nextLoc;
}
//Sets the next location that the packet will move to.
void Packet::setNextLoc(int aNext){
	nextLoc = aNext;
}

