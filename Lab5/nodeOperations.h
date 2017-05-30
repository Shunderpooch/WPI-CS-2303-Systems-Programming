//Author Arthur Dooner, CS2303, Lab 5
#ifndef __NODEOPERATIONS_H_INCLUDED__
#define __NODEOPERATIONS_H_INCLUDED__
#include "Node.h"
using namespace std;

class nodeOperations{
	public: 
		nodeOperations();
		bool addEvent(Link);
		void bringToBack(Link);
		Link getNextEvent();
		int getLength();
		bool decrementTime();
	private:
		Link sPtr;
};

#endif
