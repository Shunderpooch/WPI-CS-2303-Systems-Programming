//Author Project Partner, CS2303, Lab 5
#include "Node.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//Creates a node from a packetID, and an arrivalTime.
Node::Node(int apacketID, int anarrivalTime){
	packetID = apacketID;
	arrivalTime = anarrivalTime;
	next = NULL;
}
//Creates a node from a packetID, arrivalTime, and a link to the next one.
Node::Node(int apacketID, int anarrivalTime, Link theNext){
	packetID = apacketID;
	arrivalTime = anarrivalTime;
	next = theNext;
}
//Gets the response time for a node
int Node::getResponseTime(){
	return (finishTime - arrivalTime);
}
//Sets the Finish Time at the specific FCFS quene.
void Node::setFinishTime(int aFinishTime){
	finishTime = aFinishTime;
}
//Gets the PacketID
int Node::getPacketID(){
	return packetID;
}
//Gets the arrival time
int Node::getArrivalTime(){
	return arrivalTime;
}
//Gets the Link to the next node
Link Node::getNext(){
	return next;
}
//Sets the Link to the next Node in the linkedList data structure 
void Node::setNext(Link theNext){
	next = theNext;
}
//Sets the propogation time for the node.
void Node::setPropogationTime(int aPropogationTime){
	propogationTime = aPropogationTime;
}
//Returns the propogation time for the node
int Node::getPropogationTime(){
	return propogationTime;
}
//Gets the sender
string Node::getSender(){
	return sender;
}
//sets the sender
void Node::setSender(string thesender){
	sender = thesender;
}
//Prints the node based on its information.
void Node::printNode(){
	cout << "The packet " << packetID << " was sent from " << sender << " and traversed the network in " << getResponseTime() << " seconds." << endl;
}
