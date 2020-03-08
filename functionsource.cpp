#include "UnorderedLinkedLists.h"

char GetChoice(int min, // VAL - the minimum choice bound
               int max) // VAL - the maximum choice bound
               {

    string  input;
    int   integerInput;
    bool  invalidInput;

    do {
        cout << "Enter a choice [" << min << " - " << max << "]: ";
        getline(cin, input);

        // convert first component of input string to integer - will be garbage
        // if it is not an integer!
        // try to make a way to read in all components until reach a non-digit char?? (can process 2+ digit options, like 11)
        integerInput = (int)input[0] - 48;

        invalidInput = (!isdigit(input[0]) ||
                       (integerInput < min || integerInput > max)
                       );

        // output error message for out of bounds / 'non-integer' input
        if (invalidInput) {
            cout << "*** Invalid Input - Please enter a valid choice. *** \n";
        }

    } while (invalidInput);

    return input[0];
}




//Initialize the list to an empty state.
//Postcondition: head = nullptr, head = nullptr, count = 0;
void initializeList(nodeType *&head, nodeType *&tail, int &count) {
	destroyList(head, tail, count);
}



//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
// otherwise it returns false.
bool isEmptyList(const nodeType *head) {
		return (head == nullptr);
}




//Function to output the data contained in each node.
//Postcondition: none
void print(const nodeType* head) {

	const nodeType *current = nullptr;
	current = head;


        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }


}



//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.
int  length(const nodeType head){

    int l;
    const nodeType *current = nullptr;
    current = &head;

    l = 0;
    while (current != nullptr) {
        l ++;
        current = current->next;
    }
    return l;
}



//Function to delete all the nodes from the list.
//Postcondition: first = nullptr, last = nullptr, count = 0;
void destroyList(nodeType *&head, nodeType *&tail, int &count) {

    while (head != nullptr) {
        deleteNode(head);
    }

	tail = nullptr;
	count = 0;
}



//Function to insert newItem at the beginning of the list.
//Postcondition: first points to the new list, newItem is
// inserted at the beginning of the list,
// last points to the last node in the list,
// and count is incremented by 1.
void insertFirst(nodeType *&head, nodeType *&tail, int &count, const int & newItem) {

    // temp pointer to the new node
    nodeType *newNode = nullptr;

    newNode = new nodeType;

    // ASSIGN DATA INTO NODE
    newNode->info = newItem;
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
        newNode-> next = head;
        head = newNode;
    }
    count ++;


}



//Function to insert newItem at the beginning of the list.
//Postcondition: first points to the new list, newItem is
// inserted at the beginning of the list,
// last points to the last node in the list,
// and count is incremented by 1.
void insertLast(nodeType *&head, nodeType *&tail, int &count, const int& newItem) {
	
	// temp pointer to the new node
	nodeType *newNode = nullptr;
	
	newNode = new nodeType;
	
	// ASSIGN DATA INTO NODE
	newNode->info = newItem;
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
	    // (now second to) last node needs to point to new node
		tail->next 	= newNode;

		// with "last" node now pointing to newNode, the actual tail needs to point
		// to newNode so newNode can become the "last node".
		tail = newNode;
	}
	count ++;
	
}

void deleteNode(nodeType *& head) {
    nodeType * current;
    current = head;

    if(isEmptyList((head))) {
        cout << "List is empty. Nothing to delete.\n";
    }
    else {
        current = head;
        head = head->next;
        delete current;
    }
}