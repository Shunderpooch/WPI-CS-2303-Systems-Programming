//Author Arthur Dooner, CS2303 Section C02 Program 4
#include "BinarySearchTree.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//Builds the binary search tree and initializes the starting pointer
BinarySearchTree::BinarySearchTree(){
	startPointer=NULL;
}

//Inserts the Binary Search Node at the starting pointer
bool BinarySearchTree::insert(string aword, int line){
	return insert(aword, line, &startPointer);
}

//Inserts the Binary Search Node in the correct position along the tree
bool BinarySearchTree::insert(string aword, int line, BinarySearchNode **start){
	//If the start pointer is empty, set the new node equal to the start
	if (*start == NULL){
		BinarySearchNode *thisNode = new BinarySearchNode(aword, line);
		(*start) = thisNode;
		return true;
	}
	//Compares the word of the start to the word at the end
	int comparison = (*start)->getWord().compare(aword);
	//If the same, only add a line
	if (comparison == 0){
		(*start)->addLine(line);
		return false;
	}
	//Moves to the left node if the comparison is greater
	if (comparison > 0){
		return insert(aword, line, &(*start)->LeftNode);
	}
	//Moves to the Right node if the comparison is lesser
	if (comparison < 0){
		return insert(aword, line, &(*start)->RightNode);
	}
	//checks to ensure if it actually worked
	else{
		cout << "huh??" << endl;
		return false;
	}
	return false;
}
//Prints the tree, by passing along the starting pointer.
void BinarySearchTree::printTree(){
	//after text file is done being parsed, set up header for the table of words
	cout << left << setw(25) << setfill(' ') << "Word" << "|" << left << setw(5) << setfill(' ') << "Count" << "|" << "Lines" << endl;
	printTree(startPointer);
	//Once it is printed, we print out the total unique words. 
	cout << left << setw(25) << setfill(' ') << "Total Unique Words" << "|";
	cout << (numOfWords(startPointer)-1) << endl;
}

//Recurses through each node and prints the nodes in alphabetical order.
void BinarySearchTree::printTree(BinarySearchNode *start){
	if(start != NULL){
		printTree(start->getLeft());
		start->printNode();
		printTree(start->getRight());
	}
}
//returns the total number of unique words
int BinarySearchTree::numOfWords(BinarySearchNode *start){
	if(start != NULL){
		int num = 1;
		num+=numOfWords(start->getLeft());
		num+=numOfWords(start->getRight());
		return num;
	}
	return 0;
}
