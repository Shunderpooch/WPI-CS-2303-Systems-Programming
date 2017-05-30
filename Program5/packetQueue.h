//Author Arthur Dooner, CS2303, Lab 5
#ifndef __NODEOPERATIONS_H_INCLUDED__
#define __NODEOPERATIONS_H_INCLUDED__
#include "Packet.h"
using namespace std;

class packetQueue{
	public: 
		packetQueue();
		bool addEvent(Link);
		void bringToBack(Link);
		Link getNextEvent();
		Link getNextEvent(Link*);
		int getLength();
		vector<Link> decrementTime();
		int getFirstSize();
		int getFirstFinish();
	private:
		Link sPtr;
};

#endif
