//Author Arthur Dooner, CS2303 C02 Program 5
#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <string>
#include <vector>
using namespace std;

class Packet{
	public: 
		Packet(int, int, int, vector<int>);
		Packet(int, int, int, vector<int>, Packet*);
		int getResponseTime();
		int getFinishTime();
		void setFinishTime(int);
		int getPacketID();
		Packet* getNext();
		Packet** getNextToAccess();
		void setNext(Packet*);
		void setPropogationTime(int);
		int getArrivalTime();
		int getPropogationTime();
		int getSender();
		void printPacket();
		vector<int> getSR();
		void printSR();
		int getNextFCFS();
		int getNextLoc();
		void setNextLoc(int);
		int getPacketSize();
		Packet* decrementItems();
		Packet *next;
	private:
		int timeStamp;
		int finishTime;
		int packetID;
		int packetSize;
		int propogationTime;
		int sender;
		int nextLoc;
		vector<int> SR;
 };

typedef Packet *Link;

#endif

