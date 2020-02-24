#include "ULL.h"

void initLinkedList(nodeType *&head, nodeType *&tail, int &count) {
	head = nullptr;
	tail = nullptr;
	count = 0;
}




// inserts <data> into a new node in the linked list specified by head and tail
void insertLinkedList(nodeType *&head, nodeType *&tail, int &count, int data) {
	
	// temp pointer to the new node
	nodeType *newNode = nullptr;
	
	newNode = new nodeType;
	
	// ASSIGN DATA INTO NODE
	newNode->info = data;
	newNode->next = nullptr;
	
	// empty list case
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	// non empty list
	else {
		tail->next 	= newNode;
		tail 		= newNode;	
	}
	count ++;
	
}


// traverses ll and prints node data
void printLinkedList(nodeType *head, nodeType *tail) {
	
	nodeType *current = nullptr;
	current = head;
	
	while (current != nullptr) {
		cout << current->info << " ";
		current = current->next;
	}
	cout << "nullptr\n";
}