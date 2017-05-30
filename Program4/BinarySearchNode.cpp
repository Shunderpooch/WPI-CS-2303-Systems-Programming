//Author Arthur Dooner, CS2303 Program 4 Section C02
#include "BinarySearchNode.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//This builds the Binary Search Node by setting the word and adding the line to the vector.
BinarySearchNode::BinarySearchNode(string aword, int line){
	word = aword;
	count = 0;
	LeftNode = NULL;
	RightNode = NULL;
	addLine(line);
}

//This adds a line to the vector, checking to ensure that the vector does not already contain the line listed.
void BinarySearchNode::addLine(int line){
	count++;
	if(listOfLines.size() == 0 || listOfLines.back() != line){
		listOfLines.push_back(line);
	}
}

//Prints the node with the word, count, and vector of lines.
void BinarySearchNode::printNode(){
	if(word=="")
		return;
	cout << left << setw(25) << setfill(' ') << word << "|" << right << setw(5) << setfill(' ') << count << "|" << left;
	printLines();
	cout << endl;
}

//Returns the Left Node in the Tree
BinarySearchNode* BinarySearchNode::getLeft(){
	return LeftNode;
}

//Returns the Right Node of the Tree
BinarySearchNode* BinarySearchNode::getRight(){
	return RightNode;
}

//Returns the string word stored by the node
string BinarySearchNode::getWord(){
	return word;
}

//Sets the Word string in the node
void BinarySearchNode::setWord(string newWord){
	word = newWord;
}

//Returns a vector of all the lines
vector<int> BinarySearchNode::getLines(){
    return listOfLines;
}

//Prints the list of all of the lines in appropriate order.
void BinarySearchNode::printLines(){
	for (unsigned int x = 0; x < listOfLines.size(); x++){
		if(x == (listOfLines.size()-1)){
			cout<< right << setw(4) << setfill(' ') << listOfLines[x];
			return;
		}
		cout << right << setw(4) << setfill(' ')<< listOfLines[x] << ",";
	}
}

