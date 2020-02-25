#include "UnorderedLinkedLists.h"

void initLinkedList(nodeType *&head, nodeType *&tail, int &count) {
	head = nullptr;
	tail = nullptr;
	count = 0;
}




// inserts data into a node that is appended at the end of a linked list, specified
// by pointers head and tail
void insertLinkedList(nodeType *&head, nodeType *&tail, int &count, int data) {
	
	// temp pointer to the new node
	nodeType *newNode = nullptr;
	
	newNode = new nodeType;
	
	// ASSIGN DATA INTO NODE
	newNode->info = data;
	newNode->next = nullptr;
	
	// empty list case
	if (head == nullptr) {
	    // give the value of newNode to head and tail
	    // this is the address of the node created in this function, pointed to
	    // by newNode
		head = newNode;
		tail = newNode;
	}
	// non empty list
	else {
	    // if not empty, we do not bother changing head.
	    // tail currently points to last of list, so the pointer in that
	    // last node needs to point to new node
		tail->next 	= newNode;

		// with "last" node now pointing to newNode, the actual tail needs to point
		// to newNode so newNode can become the "last node".
		tail = newNode;
	}
	count ++;
	
}


// traverses ll and prints node data
void printLinkedList(nodeType *head, nodeType *tail) {
	
	nodeType *current = nullptr;
	current = head;
	
	while (current != nullptr) {
        cout << &current->info << "\t" << current->info << endl;
        current = current->next;
    }
	cout << endl;
}