//Author Arthur Dooner, CS2303, Lab 5
#ifndef __FCFS_H_INCLUDED__
#define __FCFS_H_INCLUDED__
#include "Node.h"
#include <vector>
#include "nodeOperations.h"
using namespace std;

class FCFS{
	public: 
		FCFS(int, int, string);
		void setSystemTime(int);
		void propogationSimulation(FCFS**, int);
		void addEvent(Link);
		int getPropogationTime();
		int getTransmissionTime();
		int getCTT();
		void setCTT(int);
		string getName();
		nodeOperations getTransmissionQuene();
		nodeOperations getPropogationQuene();
		Link getNextInTQ();
		void sendToTQ(Link);
		void sendToPQ(Link);
	private:
		int propogationTime;
		int transmissionTime;
		int cTT;
		string name;
		nodeOperations transmissionQuene;
		nodeOperations propogationQuene;
};
class Mule: public FCFS{
public:
	Mule (int x, int y, string z) : FCFS(x, y, z){}
	int runner(FCFS**, int);
};

class Sender: public FCFS{
public:
	Sender(int x, int y, string z) : FCFS(x, y, z){}
	void runner(FCFS**, int);
	void addFromFile(string, int);
};

class Receiver: public FCFS{
public:
	Receiver(string z) : FCFS(-1, -1, z){}
	void addEventReceiverSpecial(Link);
	int getSize();
	//cout << "The largest bottleneck for M1 was " << LongestTimeM1 << " packets at " << simTime1 << "sims." << endl;
	void printAverageTimes();
private:
	vector<int> allTimesS1;
	vector<int> allTimesS2;
};

#endif
