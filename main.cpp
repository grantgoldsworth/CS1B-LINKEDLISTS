/*******************************************
 * AUTHOR   : GRANT GOLDSWORTH
 * ID	    : 1164709
 * PROJECT  : A29
 * DUE DATE : 3/9/2020
*******************************************/

#include "UnorderedLinkedLists.h"

/*******************************************************************************
 * LINKED LISTS
 * -----------------------------------------------------------------------------
 * This is a menu driven program that allows the user to create and manipulate
 * a simple unordered linked list of integers.
 *
 * The modules include a list initialization, a check to see if it is empty,
 * a method to obtain the length, to print the list, destroy the list, and append
 * nodes to the front or back of the list.
 *
 * INPUT
 *      - User choice for menu options and navigation
 *      - data for a node
 *
 * OUTPUT
 *      - output text for menus and the list
 *******************************************************************************/

int main() {

    system("cls");

    /*****************************************************************************
     * VARIABLES
     * ---------------------------------------------------------------------------
     * head                 : a nodeType pointer to the head node of the list
     * tail                 : a nodeType pointer to the tail node of the list
     * count                : the unofficial number of nodes in the list
     * functionCallLength   : variable with a fancy name, just holds the length from the
     *                          return of length()
     * userInfo             : user input information for a node
     * choice               : user's menu navigation choice
     * initialized          : whether or not the list has been properly initialized,
     *                          used to control if user can input into uninit'd list
     *****************************************************************************/

    nodeType * head = nullptr;
    nodeType * tail = nullptr;
    int count = 0;
    int functionCallLength;
    int userInfo;
	char choice;
	bool initialized;

	initialized = false;

	do { // while (choice != 8) -- main menu driver
		// output the main menu
		cout << "\n\t\t-----[ LINKED LIST STUFF ]-----\n\n";
		cout << "[1] initializeList\n";
		cout << "[2] isEmptyList\n";
		cout << "[3] print\n";
		cout << "[4] length\n";
		cout << "[5] destroyList\n";
		cout << "[6] insertFirst\n";
		cout << "[7] insertLast\n";
		cout << "[8] Exit\n\n";
		
		choice = GetChoice(1, 8);
		cout << endl;
		
		switch (choice) {

		    /* INITIALIZE THE LIST */
			case '1':
				initializeList(head, tail, count);
                cout << "List has been initialized.\n\n";
                initialized = true;
                system("pause");
				break;

            /* CHECK IF LIST IS EMPTY */
			case '2':
				if (isEmptyList(head)) {
				    cout << "The list is empty.\n";
				}
				else {
				    cout << "The list is not empty.\n";
				}
				system("pause");
				break;

            /* OUTPUT CONTENTS OF LIST IF NOT EMPTY */
			case '3':
			    if (isEmptyList(head)) {
                    cout << "List is empty.\n";
                }
			    else {
                    cout << "Contents of the list:\n";
                    cout << "[ ";
                    print(head);
                    cout << "]\n";

			    }
				system("pause");
				break;

            /* OUTPUT NUMBER OF ELEMENTS IN THE LIST */
            case '4':
                if (!isEmptyList(head)) {
                    cout << "Elements in linked list: " << length(*head) << endl;
                }
                else {
                    cout << "List is empty.\n";
                }
                system("pause");
                break;

            /* DESTROY THE LIST */
            case '5':
                if (!isEmptyList(head)) {
                    cout << "Destroying list...\n";
                    destroyList(head, tail, count);
                    initialized = false;
                }
                else {
                    cout << "The list is empty.\n";
                }

				system("pause");
				break;

            /* HEAD APPEND A NODE */
			case '6':
			    if (initialized) {
                    cout << "Insert a node to the front of the list\n";
                    cout << "Enter data for node: ";
                    cin >> userInfo;
                    cin.ignore(1000, '\n');
                    insertFirst(head, tail, count, userInfo);
                }
			    else {
			        cout << "ERROR - List has not been initialized. Can not add data to list.\n";
			        system("pause");
			    }
				break;

            /* TAIL APPEND A NODE */
		    case '7':
		        if (initialized) {
                    cout << "Insert a node to the end of the list\n";
                    cout << "Enter data for node: ";
                    cin >> userInfo;
                    cin.ignore(1000, '\n');
                    insertLast(head, tail, count, userInfo);
                }
		        else {
		            cout << "ERROR - List has not been initialized. Can not add data to list.\n";
		            system("pause");
		        }
		        break;
			
			default:
				break;
		}

		cout << endl;
		system("cls");
		
	}while (choice != '8');
	
	
    return 0;
}
