#include <iostream>
#include <windows.h>
using namespace std;

#ifndef _ULL
#define _ULL


struct nodeType {
	int info;
	nodeType *next;
};


void initLinkedList(nodeType *&, nodeType *&, int &);

void insertLinkedList(nodeType *&, nodeType *&, int &, int);

void printLinkedList(nodeType *, nodeType *);


#endif