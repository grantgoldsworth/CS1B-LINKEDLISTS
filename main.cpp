#include "ULL.h"

int main() {
	
	system("cls");
	
	nodeType *head;
	nodeType *tail;
	int count;
	
	// create new empty node
	initLinkedList(head, tail, count);
	
	insertLinkedList(head, tail, count, 5);
	insertLinkedList(head, tail, count, 2);
	
	printLinkedList(head, tail);
	
	system("pause");
	
	// NEED TO DELETE DYNAMIC MEMORY
	
	return 0;
}

