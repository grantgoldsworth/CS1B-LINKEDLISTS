/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A29
 * DUE DATE : 3/9/2020
*******************************************/

#include "UnorderedLinkedLists.h"

/******************************************************************************
 * FUNCTION - GetChoice
 * ____________________________________________________________________________
 * This function receives two integers representing a min and a max bound.
 * It will prompt the user to enter a digit until the conditions are satisfied:
 * it is an integer digit, and it is between the bounds
 * ===> returns integer choice
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			min: the integer to represent the minimum choice for a menu
 * 			max: the integer to represent the maximum choice for a menu
 *
 * POST-CONDITIONS
 *		This function will return a character
 ******************************************************************************/

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




/******************************************************************************
 * FUNCTION - initializeList
 * ____________________________________________________________________________
 * This function receives two nodeType pointers and an integer. It will set
 * the pointers to nullptr and count to 0 by calling on the destroyList
 * function.
 * ===> returns nothing. actual parameters are modified
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head  : pointer to the head node of the list, any value
 * 			max   : pointer to the tail node of the list, any value
 * 			count : the number of elements in the list
 *
 * 			destroyList : a function that formally deletes the list
 * 			                and sets pointers to null/count to 0
 *
 * POST-CONDITIONS
 *		This function return nothing.
 *		actual arguments head and tail are set to nullptr, count is set to 0.
 ******************************************************************************/

//Initialize the list to an empty state.
//Postcondition: head = nullptr, head = nullptr, count = 0;
void initializeList(nodeType *&head, nodeType *&tail, int &count) {
	destroyList(head, tail, count);
}




/******************************************************************************
 * FUNCTION - isEmptyList
 * ____________________________________________________________________________
 * This function receives a pointer to the head node of the list. It will
 * return true if the list is empty, and false if it is not.
 * ===> returns a boolean
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head  : pointer to the head node of the list, any value
 *
 * POST-CONDITIONS
 *		This function returns true if head is null, and false otherwise.
 ******************************************************************************/

//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
// otherwise it returns false.
bool isEmptyList(const nodeType *head) {
		return (head == nullptr);
}




/******************************************************************************
 * FUNCTION - print
 * ____________________________________________________________________________
 * This function receives a pointer to the head node of the list. It will output
 * the info member of each nodeType in the list.
 * ===> returns nothing
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head  : pointer to the head node of the list, any value
 *
 * POST-CONDITIONS
 *		This function returns nothing. Outputs text.
 ******************************************************************************/

//Function to output the data contained in each node.
//Postcondition: none
void print(const nodeType head) {

	const nodeType *current = nullptr;
	current = &head;


        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }


}




/******************************************************************************
 * FUNCTION - length
 * ____________________________________________________________________________
 * This function receives a nodeType. It will formally calculate and output
 * the number of nodes in the list.
 * ===> returns integer
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head  : a copy of the head node of the list
 *
 * POST-CONDITIONS
 *		This function returns integer representing node count.
 ******************************************************************************/

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




/******************************************************************************
 * FUNCTION - destroyList
 * ____________________________________________________________________________
 * This function receives two nodeType pointers and an integer. It will
 * effectively destroy the list by calling deleteNode on each node
 * in the list, and sets the pointers to null, and counter to 0.
 * ===> returns integer
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head  : pointer to the head node of the list, any value
 * 			max   : pointer to the tail node of the list, any value
 * 			count : the number of elements in the list
 *
 * 			deleteNode  : a function to completely delete a single node
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified.
 ******************************************************************************/

//Function to delete all the nodes from the list.
//Postcondition: first = nullptr, last = nullptr, count = 0;
void destroyList(nodeType *&head, nodeType *&tail, int &count) {

    while (head != nullptr) {
        deleteNode(head);
    }

	tail = nullptr;
	count = 0;
}




/******************************************************************************
 * FUNCTION - insertFirst
 * ____________________________________________________________________________
 * This function receives two nodeType pointers and two integers. It will
 * head append a node to the list, adjusting the proper pointers to it
 * and increasing the count. Data is stored into the new node.
 * ===> returns nothing. actual parameters are modified.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head    : pointer to the head node of the list, any value
 * 			max     : pointer to the tail node of the list, any value
 * 			count   : the number of elements in the list
 * 			newItem : the data to store into the new node
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified.
 ******************************************************************************/

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





/******************************************************************************
 * FUNCTION - insertLast
 * ____________________________________________________________________________
 * This function receives two nodeType pointers and two integers. It will
 * tail append a node to the list, adjusting the proper pointers to it
 * and increasing the count. Data is stored into the new node.
 * ===> returns nothing. actual parameters are modified.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head    : pointer to the head node of the list, any value
 * 			max     : pointer to the tail node of the list, any value
 * 			count   : the number of elements in the list
 * 			newItem : the data to store into the new node
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified.
 ******************************************************************************/

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




/******************************************************************************
 * FUNCTION - destroyList
 * ____________________________________________________________________________
 * This function receives a nodeType pointer. It will delete the node pointed
 * to by parameter node, including the dynamic memory.
 * NOTE: in current development stage, node must effectively be the head pointer -
 * the next value is adjusted as if it is. Will not work on a different
 * node.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			node    : pointer to the node to delete, must be the head pointer
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified:
 *		    current node is formally deleted
 *		    node points to the next node
 ******************************************************************************/

void deleteNode(nodeType *& node) {
    nodeType * current;
    current = node;

    if(isEmptyList((node))) {
        cout << "List is empty. Nothing to delete.\n";
    }
    else {
        current = node;
        node = node->next;
        delete current;
    }
}