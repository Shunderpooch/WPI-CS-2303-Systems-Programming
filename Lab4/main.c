//Arthur Dooner, CS2303 Section C02, ajdooner@wpi.edu
//Lab 4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DEBUG 1

//Creates the Node of a Binary Search Tree
typedef struct BSTNODE{
	long studentID;
	float grade1, grade2, grade3, average;
	struct BSTNODE *leftNode, *rightNode;
}BST;

//Pointer type to the Binary search trees
typedef BST *BSTPtr;

//Takes the pointer to the beginning and 3 grades, then creates and
//inserts the struct to the correct position
int insert(BSTPtr *sPtr, long studentID, float grade1, float grade2, float grade3){
	BSTPtr ourPtr=*sPtr;
	//If we're at the top of the tree
	if(ourPtr == NULL){
		ourPtr=malloc(sizeof(BST));
		ourPtr->studentID = studentID;
		ourPtr->grade1 = grade1;
		ourPtr->grade2 = grade3;
		ourPtr->grade3 = grade3;
		ourPtr->average = (grade1+grade2+grade3)/3;
		ourPtr->leftNode = NULL;
		ourPtr->rightNode = NULL;
		*sPtr=ourPtr;
		return 1;
	}
	//If the studentID is smaller than the one at the top
	else if (studentID < ourPtr->studentID){
		insert(&(ourPtr->leftNode), studentID, grade1, grade2, grade3);
		return 1;
	}
	//If the studentID is larger than the one at the top
	else if (studentID > ourPtr->studentID){
		insert(&(ourPtr->rightNode), studentID, grade1, grade2, grade3);
		return 1;
	}
	else{
		return 2;
	}

}
//Prints the contents of the tree from top to bottom
void print_tree(BSTPtr sPtr, int Header){
	if (Header == 1){
		printf("\nStudentID|Grade1|Grade2|Grade3|Average|\n");
		printf("---------------------------------------\n");
	}
	if(sPtr != NULL){
		print_tree((sPtr->leftNode), 0);
		printf("%9lu|%6.1f|%6.1f|%6.1f|%7.1f|\n", sPtr->studentID, sPtr->grade1, sPtr->grade2, sPtr->grade3, sPtr->average);
		print_tree(sPtr->rightNode, 0);
	}
}
//Takes in an arbitrary amount of student lines of input, inserts each
//node into the BST, and prints the tree.
int main(int argc, char *argv[]){
	if (argv[1] == NULL){
		printf("Please run this program again in the correct format:\n ./<executable> <number of Students>\n");
		return 1;
	}
	int numberOfStudents = atoi(argv[1]);
	BSTPtr sPtr = NULL;
	long studentID;
	float grade1, grade2, grade3;
	for(int x = 0; x < numberOfStudents; x++){
		printf("Please input student %d and their information in the form: \n StudentID Grade1 Grade2 Grade3 \n ", (x+1));
		scanf("%ld %f %f %f", &studentID, &grade1, &grade2, 
&grade3);
		insert(&sPtr, studentID, grade1, grade2, grade3);
	}
	print_tree(sPtr, 1);
	return 1;
}
