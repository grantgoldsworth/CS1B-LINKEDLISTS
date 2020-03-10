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
 * -------------------------------------------------------------------------------------
 * ALGORITHM
 *  1 present the main menu and ask for input, error checking it
 *  2 navigate to menu module based on user input
 *      - initialize a linked list and allow user to build it via head/tail append
 *      - see if list is empty
 *      - search the list for an item
 *      - destroy the list
 *      - print list elements and length
 *      - delete a single node from the list
 *      - copy into a seperate linked list
 *******************************************************************************/

int main() {

    system("cls");

    /*****************************************************************************
     * VARIABLES
     * ---------------------------------------------------------------------------
     * aHead                 : a nodeType pointer to the Head node of the list
     * aTail                 : a nodeType pointer to the Tail node of the list
     * count                : the unofficial number of nodes in the list
     * functionCallLength   : variable with a fancy name, just holds the length from the
     *                          return of length()
     * userInfo             : user input information for a node
     * choice               : user's menu navigation choice
     * initialized          : whether or not the list has been properly initialized,
     *                          used to control if user can input into uninit'd list
     * deleteItem           : used in deleteNode, the item user wants deleted from list
     * searchItem           : item to search for in the list
     *****************************************************************************/

    nodeType * aHead = nullptr;
    nodeType * aTail = nullptr;
    int        aCount = 0;

    nodeType * bHead = nullptr;
    nodeType * bTail = nullptr;
    int bCount = 0;

    int  functionCallLength;
    int  userInfo;
	int  choice;
	bool initialized;
    int  deleteItem;
    int  searchItem;

	initialized = false;

	/********************************************************************
	 * DO-WHILE - Main Menu
	 * This loop drives the main menu for the program.
	 * It will prompt a menu and ask user for a selection, and error check until
	 * a valid input is entered.
	 * Allow navigation of menu modules
	 ********************************************************************/

	do { // while (choice != 8) -- main menu driver
		// output the main menu
		cout << "\n\t\t-----[ LINKED LIST STUFF ]-----\n\n";
		cout << "[0] initializeList\n";
		cout << "[1] isEmptyList\n";
		cout << "[2] print\n";
		cout << "[3] length\n";
		cout << "[4] destroyList\n";
		cout << "[5] search\n";
		cout << "[6] insertFirst\n";
		cout << "[7] insertLast\n";
		cout << "[8] deleteNode\n";
		cout << "[9] copyList\n";
		cout << "[10] Exit\n\n";

		choice = GetChoice(0, 10);
		cout << endl;
		
		switch (choice) {

		    /* INITIALIZE THE LIST */
			case 0:
				initializeList(aHead, aTail, aCount);
                cout << "List has been initialized.\n\n";
                initialized = true;
                system("pause");
				break;


            /* CHECK IF LIST IS EMPTY */
			case 1:
			    if (initialized) {
                    if (isEmptyList(aHead)) {
                        cout << "The list is empty.\n";
                    } else {
                        cout << "The list is not empty.\n";
                    }
                }
			    else {
			        cout << "List has not been initialized. Can not find length\n";
			    }
				system("pause");
				break;


            /* OUTPUT CONTENTS OF LIST IF NOT EMPTY */
			case 2:
			    if (initialized) {
                    if (isEmptyList(aHead)) {
                        cout << "List is empty.\n";
                    } else {
                        cout << "Contents of list A:\n";
                        cout << "[ ";
                        print(*aHead);
                        cout << "]\n";

                        if (!isEmptyList(bHead)) {
                            cout << "\nContents of list B:\n";
                            cout << "[ ";
                            print(*bHead);
                            cout << "]\n";
                        }

                    }
                }
			    else {
                    cout << "List has not been initialized - can not print.\n";
			    }
				system("pause");
				break;


            /* OUTPUT NUMBER OF ELEMENTS IN THE LIST */
            case 3:
                if (initialized) {
                    if (!isEmptyList(aHead)) {
                        cout << "Elements in linked list: " << length(*aHead) << endl;
                    } else {
                        cout << "List is empty.\n";
                    }
                }
                else {
                    cout << "List has not been initialized - can not find length.\n";
                }
                system("pause");
                break;


            /* DESTROY THE LIST */
            case 4:
                if (initialized) {
                    if (!isEmptyList(aHead)) {
                        destroyList(aHead, aTail, aCount);
                        cout << "List destroyed, need to initialize before using it again.\n";
                        initialized = false;
                        system("pause");
                    }
                    else {
                        cout << "List is empty. Nothing to destroy.\n";
                        system("pause");
                    }
                }
                else {
                    cout << "List has not been initialized - cannot destroy list.\n";
                    system("pause");
                }
				break;


            /* SEARCH */
		    case 5:
		        if (initialized) {
		            if (!isEmptyList(aHead)) {
		                cout << "Enter an item to search for in the list: ";
		                while (!(cin >> searchItem)) {
		                    cout << "Enter a valid search item [int]: ";
		                    cin.clear();
		                    cin.ignore(100, '\n');
		                }
		                if (search(aHead, searchItem)) {
		                    cout << "<" << searchItem << "> was found in the list.\n";
		                }
		                else {
                            cout << "<" << searchItem << "> was not found in the list.\n";
		                } // end if (search(searchItem)) else
		            } // end if (!isEmptyList(aHead))
		            else {
		                cout << "The list is empty. Nothing to search through.\n";
		            }

		        } // end if (initialized)
		        else {
		            cout << "List has not been initialized. Can not perform search.\n";
		        }
		        system("pause");
		        break;


            /* HEAD APPEND A NODE */
			case 6:
			    if (initialized) {
                    cout << "Insert a node to the front of the list\n";
                    cout << "Enter data for node: ";
                    cin >> userInfo;
                    cin.ignore(1000, '\n');
                    insertFirst(aHead, aTail, aCount, userInfo);
                }
			    else {
			        cout << "ERROR - List has not been initialized. Can not add data to list.\n";
			        system("pause");
			    }
				break;

            /* TAIL APPEND A NODE */
		    case 7:
		        if (initialized) {
                    cout << "Insert a node to the end of the list\n";
                    cout << "Enter data for node: ";
                    cin >> userInfo;
                    cin.ignore(1000, '\n');
                    insertLast(aHead, aTail, aCount, userInfo);
                }
		        else {
		            cout << "ERROR - List has not been initialized. Can not add data to list.\n";
		            system("pause");
		        }
		        break;

            /* DELETE A NODE */
            case 8:
                if (initialized) {
                    if (!isEmptyList(aHead)) {
                        cout << "Enter an item to delete (will delete first instance of item in list): ";
                        while (!(cin >> deleteItem)) {
                            cout << "ERROR - Enter a valid data option (int): ";
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }

                        deleteNode(aHead,aTail, aCount, deleteItem);

                    } // end if (!IsEmptyList(aHead))
                    else {
                        cout << "List is empty - nothing to delete.\n";
                    }
                } // end if (initialized)

                else {
                    cout << "ERROR - List has not been initialized. Can not search for delete item.\n";
                }

                system("pause");

                break;


            /* COPY LIST A*/
		    case 9:
		        if (initialized) {
		            if (!isEmptyList(aHead)) {
                        cout << "Copied list A into list B.\n";
                        copyList(aHead, bHead, bTail, bCount);
                    }

		            else {
		                cout << "List is empty. Nothing to copy.\n";
		            } // end if (!isEmptyList(aHead)) else

                } // end if (initialized)
		        else {
                    cout << "Source list has not been initialized - can not perform copy\n.";
		        }

		        system("pause");
		        break;

			default:
				break;
		}

		cout << endl;
		system("cls");
		
	}while (tolower(choice) != 10);
	
	destroyList(aHead, aTail, aCount);
	destroyList(bHead, bTail, bCount);
    return 0;
}
