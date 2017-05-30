//Author Arthur Dooner, CS2303 Section C02, Program 4
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BinarySearchNode{
	public:
		BinarySearchNode(string, int);
		string getWord();
		void setWord(string);
		BinarySearchNode* getLeft();
		BinarySearchNode* getRight();
		void printNode();
        	vector<int> getLines();
        	void addLine(int);
        	void printLines();
		BinarySearchNode* LeftNode;
		BinarySearchNode* RightNode;
	private:
        	vector<int> listOfLines;
        	int count;
        	string word;
};
