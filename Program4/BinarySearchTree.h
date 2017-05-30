//Author Arthur Dooner, CS2303 Program 4 Section C02
#include "BinarySearchNode.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BinarySearchTree{
	public:
		BinarySearchTree();
		bool insert(string, int);
		void printTree();
		int numOfWords(BinarySearchNode*);
	private:
		BinarySearchNode* startPointer;
		bool insert(string, int, BinarySearchNode**);
		void printTree(BinarySearchNode*);
		

};
