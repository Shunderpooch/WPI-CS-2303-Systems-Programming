//Author Arthur Dooner, CS2303, Lab 5
#include "FCFS.h"
#include "nodeOperations.h"
#include "Node.h"
#include "globals.h"
#include <iostream>

using namespace std;

int main()
{
	int simTime = 1;
	/*Initialize pointers to every sender, mule, and receiver.*/
	Sender *S1 = new Sender(2, 1, "S1");
	Sender *S2 = new Sender(2, 1, "S2");
	Mule *M1 = new Mule(3, 2, "M1");
	Mule *M2 = new Mule(5, 2, "M2");
	Receiver *R1 = new Receiver("R1");
	//Add the first two to each packet so they have a starting point.
	S1->addFromFile("packetIDs", 0);
	S2->addFromFile("packetIDs", 3);
	int LongestTimeM1 = 0; 
	int LongestTimeM2 = 0;
	int simTime1, simTime2;
	//While R1 is not full
	while (R1->getSize() < 200){
		int temp1, temp2;	
		if (DEBUG){
			cout << endl << simTime << " sims:" << endl << endl;
		}
		temp2 = M2->runner((FCFS**)&R1, simTime);
		if (temp2 > LongestTimeM2){
			LongestTimeM2 = temp2;
			simTime2 = simTime;
		}
		temp1 = M1->runner((FCFS**)&M2, simTime);
		if (temp1 > LongestTimeM1){
			LongestTimeM1 = temp1;
			simTime1 = simTime;
		}
		S1->runner((FCFS**)&M1, simTime);
		if(simTime > 2){
			S2->runner((FCFS**)&M1, simTime);
		}
		simTime++;

	}
	R1->printAverageTimes();
	cout << "The largest bottleneck for M1 was " << LongestTimeM1 << " packets at " << simTime1 << " sims." << endl;
	cout << "The largest bottleneck for M2 was " << LongestTimeM2 << " packets at " << simTime2 << " sims." << endl;	
	return 0;
}
