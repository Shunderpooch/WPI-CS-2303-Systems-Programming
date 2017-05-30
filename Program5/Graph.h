//Attempted by Project Partner
//Code did not work
//Rewritten by Author Arthur Dooner, CS2303, Program 5
#ifndef __GRAPH_H_INCLUDED__
#define __GRAPH_H_INCLUDED__
#include "FCFS.h"
class Graph{
	public:
		Graph(int, int, int, int);
		//Multi Dimensional Arrays are not as you would think to use them.
		void addToGrid(Sender*);
		void addToGrid(Mule*);
		void addToGrid(Receiver*);
		void printGrid(int);
		void moveMule(Mule**);
		void makeMove(Mule**, int, int);
		void moveManyMules();
		bool runARound(int);
		void runSimulation();
	private:
		vector<vector<int> > manetmap;
		vector<FCFS*> *items;
		int senderCount, receiverCount, muleCount;
		int countOfItems;
		int dimension;
};

#endif

