//Author Arthur Dooner, CS2303 C02 Lab5
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <string>
using namespace std;

class Node{
	public: 
		Node(int, int);
		Node(int, int, Node*);
		int getResponseTime();
		void setFinishTime(int);
		int getPacketID();
		Node* getNext();
		void setNext(Node*);
		void setPropogationTime(int);
		int getArrivalTime();
		int getPropogationTime();
		string getSender();
		void setSender(string);
		void printNode();
	private:
		int arrivalTime;
		int finishTime;
		int packetID;
		int propogationTime;
		string sender;
		Node *next; 
};

typedef Node *Link;

#endif

