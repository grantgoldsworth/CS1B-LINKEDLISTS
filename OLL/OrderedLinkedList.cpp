/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A31
 * DUE DATE : 3/?/2020
*******************************************/

#include "LinkedList.h"

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

int GetChoice(int min,
               int max)
               {

    int input;
    cout << "Enter a selection  [" << min << " - " << max << "]: ";

    while (!(cin >> input) || (input > max || input < min)) {
        cout << "ERROR - Enter a valid selection [" << min << " - " << max << "]: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }


    return input;
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
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified.
 ******************************************************************************/

//Function to delete all the nodes from the list.
//Postcondition: first = nullptr, last = nullptr, count = 0;
void destroyList(nodeType *&head, nodeType *&tail, int &count) {

	nodeType * current = nullptr;

    while (head != nullptr) {
		current = head;
        head = head->next;
		delete current;
    }

	head = nullptr;
	tail = nullptr;
	count = 0;
}



/******************************************************************************
 * FUNCTION - search
 * ____________________________________________________________________________
 * This function receives two nodeType pointers and a search item. It will
 * traverse the list and return true if the item is found, or false otherwise
 * ===> returns integer
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 			head       : pointer to the head node of the list, any value
 * 			max        : pointer to the tail node of the list, any value
 * 			searchItem : the item to search for in the list
 *
 *
 * POST-CONDITIONS
 *		This function returns a boolean
 ******************************************************************************/

//Function to determine whether searchItem is in the list.
//Postcondition: Returns true if searchItem is in the
// list, otherwise the value false is
// returned.
bool search(nodeType *srcHead, const int &searchItem) {
    nodeType * current = nullptr;
    current = srcHead;

    bool found = false;
	bool stop = false;

	if(!isEmptyList(head)) {

		// traverse list and check for a match, exit if
		// one is found
		while (current != nullptr && !stop) {
			if (current-> info >= searchItem) {
				stop = true;
			}
			else {
				current = current->next;
			}
		}


	} // end if (!isEmptyList())
	else {
		
	}
    return found;
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
 * FUNCTION - deleteNode
 * ____________________________________________________________________________
 * This function gets a head, tail, count, and item to delete for a list and
 * searches the list for the item. If a node with the item is found,
 * it deletes the node (first occurance of the item)
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    head        : pointer to the head of the list
 * 		    tail        : pointer to the tail of the list
 * 		    count       : unofficial number of nodes in the list
 * 		    deleteItem  : the item to search for and delete from list
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified:
 *		    if target is found:
 *		        node with target is deleted
 *		        nodes around deleted node are patched
 *		        count is decremented
 ******************************************************************************/

//Function to delete deleteItem from the list.
//Postcondition: If found, the node containing
// deleteItem is deleted from the list.
// first points to the first node, last
// points to the last node of the updated
// list, and count is decremented by 1
void deleteNode(nodeType *&head, nodeType *&tail, int &count, const int& deleteItem) {
	nodeType *current  = nullptr;
	nodeType *previous = nullptr;
    bool found = false;

	current = head;

	// case 1 : list is empty
	if (isEmptyList(head)) {
		cout << "The list is empty. Can not delete node.\n";
	}
	
	// case 2: deleteItem is in head node
	else if (deleteItem == head->info) {
		current = head;
		head = head->next;
		count --;

		// check if 1 - node list
		if (head == nullptr) {
		    tail = nullptr;
		}
		
		delete current;
		current = nullptr;
	}
	
	// case 3: deleteItem is somewhere in list besides head node
	else {
		previous = head;
		current = current->next;

		// search rest of the list, traversing until something is found
		// or reached the end of the list
		while (current != nullptr && !found) {

		    // traverse list only while having not found a match.
		    // Exit list if end of list is reached without a match

		    // check if there is a match, and set found to true if so.
		    if (deleteItem != current->info) {
		        previous = current;
		        current = current->next;
		    }
		    // found a match
		    else {
		        found = true;
		    }
		    // if a match is found, loop will exit with current pointing to the match and
		    // previous pointing to the node before it
		} // end while (current != nullptr && !found)

		// post loop processing:
		//  + check if it is the tail node
		//  + set the previous pointer to point to the one
		//    after the deleted
		//  + delete the target node

        // if match was found
        if (found) {
            // update and secure new links
            previous->next = current->next;
            count --;

            // if the delete target is the tail, update
            // the tail to point to the previous node
            if (tail == current) {
                tail = previous;
            }

            // delete the target node
            delete current;
        }
        // not found
        else {
            cout << "The item <" << deleteItem << "> was not found in the list\n";
        }


			
	} // end if (isEmptyList) else if (deleteItem == head->info) else
	
}




/******************************************************************************
 * FUNCTION - copyList
 * ____________________________________________________________________________
 * This function will perform a deep copy of the source list into a seperate
 * linked list. There will be no connection between the lists via pointers.
 * PRE-CONDITIONS
 * 		Following must be defined prior to function call:
 * 		    srcHead     : head of node to copy from
 * 		    dstHead     : head of node to copy to
 * 		    dstTail     : tail of node to copy to
 * 		    dstCount    : the count attribute for destination list
 *
 * POST-CONDITIONS
 *		This function returns nothing.
 *		Actual parameters are modified:
 *		    head and tail nodes of destination list are initialized and assigned
 *		    values of new linked list
 *		    dstCount is given number of nodes copied over from src
 *
 ******************************************************************************/

//Function to make a copy of otherList (src).
//Postcondition: A copy of otherList(src) is created and
// assigned to this list (dst).
void copyList(nodeType *srcHead, nodeType *&dstHead, nodeType *&dstTail, int &dstCount) {
    nodeType * current = nullptr;

    // initialize destination list
    dstHead = nullptr;
    dstTail = nullptr;
    dstCount = 0;

    current = srcHead;
    while (current != nullptr) {
        insertLast(dstHead, dstTail, dstCount, current->info);
        current = current->next;
    }
}