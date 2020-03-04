#include <iostream>
#include <windows.h>
using namespace std;

#ifndef _ULL
#define _ULL


struct nodeType {
	int info;
	nodeType *next;
};

char GetChoice(int, int);


void initializeList(nodeType *&, nodeType *&, int &);
//Initialize the list to an empty state.
//Postcondition: head = nullptr, head = nullptr, count = 0;

bool isEmptyList(const nodeType *);
//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
// otherwise it returns false.

void print(const nodeType *);

int  length(); 

void destroyList(nodeType *&, nodeType *&, int &);

void insertFirst(nodeType *&, nodeType *&, int &, const int &);

void tailInsertLinkedList(nodeType *&, nodeType *&, int &, int);

void insertLinkedList(nodeType *&, nodeType *&, int &, int, int);

void deleteNode();




#endif