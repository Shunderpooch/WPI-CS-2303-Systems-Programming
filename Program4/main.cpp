//Author Program Partner of team H2, CS2303 Section 2 Program 4
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "BinarySearchTree.h"

using namespace std;

//Author: Program Partner
//Main function
int main()
{
	//Declaring all the initial variables
	BinarySearchTree Tree;
	string readline;
	string word;
	string temp;
	char curchar;
	int linenum = 0;
	int length = 0;
	int firstchar = 0;
	int i = 0;
	
	//While the given text file has yet to run out
	while(getline(cin, readline)!=NULL)
		{
		//At each new line, increment the line number and reset variables
		linenum++;
		i = 0;
		length = 0;
		firstchar = 0;
		//Loops through the currently read line
		while(readline[i])
			{
			//holds the current character, then increases length of substring by one
			curchar = readline[i];
			length++;
			//if the character is a blank, tab, or punctuation that isn't "'", a substring of the word is created
			if(isspace(curchar) || (ispunct(curchar) && readline[i]!='\''))
				{
				//creates word, makes it lowercase, and inserts it into the tree.
				word = readline.substr(firstchar, length-1);
				for(unsigned int y = 0; y<word.size(); y++)
					word[y] = tolower(word[y]);
				Tree.insert(word, linenum);
				length = 0;
				//moves first character for the next word up.
				firstchar = i+1;
				}
			//increments i for the while loop
			i++;
			}
		//When the END of a line is reached, it's necessary to grab the last word this way, similarly to inside the above if block.
		word = readline.substr(firstchar, length);
		for(unsigned int y=0; y<word.size(); y++)
			word[y] = tolower(word[y]);
		Tree.insert(word, linenum);
		}
		

	//prints the table of words
	Tree.printTree();
	return 0;
}
