//Author Arthur Dooner, CS2303, Program 5
#ifndef __FCFS_H_INCLUDED__
#define __FCFS_H_INCLUDED__
#include "Packet.h"
#include "globals.h"
#include <vector>
#include "packetQueue.h"

using namespace std;

class FCFS{
	public: 
		FCFS(int, int);
		void propogationSimulation(vector<FCFS*>**, int);
		void addEvent(Link);
		int getArrivalTime();
		int getCTT();
		void setCTT(int);
		int getID();
		int getLocY();
		void setLoc(int, int);
		int getLocX();
		DIRECTION getDirection();
		void setDirection(DIRECTION);
		void invertDirection();
		packetQueue getTransmissionQueue();
		packetQueue getPropogationQueue();
		Link getNextInTQ();
		void sendToTQ(Link);
		void sendToPQ(Link);
		void printFCFS();
		int getDistanceFrom(int, vector<FCFS*>**);
	private:
		int arrivalTime;
		int cTT;
		int ID;
		int locY;
		int locX;
		DIRECTION dir;
		packetQueue transmissionQueue;
		packetQueue propogationQueue;
};
class Mule: public FCFS{
	public:
		Mule (int anID) : FCFS(anID, 0){
			switch (getID() % 4){
				case 0:
					setDirection(NORTH);
					break;
				case 1:
					setDirection(SOUTH);
					break;
				case 2:
					setDirection(EAST);
					break;
				case 3:
					setDirection(WEST);
					break;
			}

		}
		bool runner(vector<FCFS*>**, int);
};

class Sender: public FCFS{
	public:
		Sender(int anID, int anArrivalTime, int thePackets, int thePacketSize, vector<int> theSR) : FCFS(anID, anArrivalTime){
			numPackets = thePackets;
			packetSize = thePacketSize;
			SR = theSR;
			counter = 0;
			setDirection(EMPTY);
		}
		bool runner(vector<FCFS*>**, int);
		int addPackets(int);
	private:
		int numPackets;
		int counter;
		int packetSize;
		vector<int> SR;
};

class Receiver: public FCFS{
public:
	Receiver(int anID) : FCFS(anID, 0){
		setDirection(EMPTY);
		numPackets = 0;
	}
	int getSize();
	void buildVectors(int);
	void printCalculations();
private:
	vector<vector<Link> > receivedItems;
	int numPackets;

};

#endif
