##Author Program Partner, CS2303, Program 4, Section C02
##Start of Makefile

make: main clean

main: main.o BinarySearchNode.o BinarySearchTree.o
	g++ main.o BinarySearchNode.o BinarySearchTree.o -o Program4

main.o: main.cpp BinarySearchNode.h BinarySearchTree.h
	g++ -Wall -c main.cpp -std=c++98

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -Wall -c BinarySearchTree.cpp -std=c++98

BinarySearchNode.o: BinarySearchNode.cpp BinarySearchNode.h BinarySearchTree.h
	g++ -Wall -c BinarySearchNode.cpp -std=c++98

clean: 
	rm *.o

##End of Makefile
