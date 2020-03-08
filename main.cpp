#include "UnorderedLinkedLists.h"

int main() {

    system("cls");

    nodeType * head = nullptr;
    nodeType * tail = nullptr;
    int count = 0;
    int functionCallLength;

    int userInfo;
	char choice;
	
	do {
		
		cout << "\n\t\t-----[ LINKED LIST STUFF ]-----\n\n";
		cout << "[1] initializeList\n";
		cout << "[2] isEmptyList\n";
		cout << "[3] print\n";
		cout << "[4] length\n";
		cout << "[5] destroyList\n";
		cout << "[6] insertFirst\n";
		cout << "[7] insertLast\n";
		cout << "[8] Exit\n\n";

		cout << "LIST: [ ";
		print(head);
		cout << "]\n\n";

		choice = GetChoice(1, 8);
		cout << endl;
		
		switch (choice) {
			
			case '1':
				initializeList(head, tail, count);
                cout << "List has been initialized.\n\n";
                system("pause");
				break;
			
			case '2':
				if (isEmptyList(head)) {
				    cout << "The list is empty.\n";
				}
				else {
				    cout << "The list is not empty.\n";
				}
				system("pause");
				break;
				
			case '3':
				cout << "Contents of the list:\n";
				cout << "[ ";
				print(head);
				cout << "]\n";
				system("pause");
				break;

            case '4':
                cout << "Elements in linked list: " << length(*head) << endl;
                system("pause");
                break;


            case '5':
				cout << "Destroying list...\n";
				destroyList(head, tail, count);
				system("pause");
				break;
				
			case '6':
				cout << "Insert a node to the front of the list\n";
				cout << "Enter data for node: ";
				cin >> userInfo;
                cin.ignore(1000, '\n');
				insertFirst(head, tail, count, userInfo);
				break;

		    case '7':
                cout << "Insert a node to the end of the list\n";
                cout << "Enter data for node: ";
                cin  >> userInfo;
                cin.ignore(1000, '\n');
                insertLast(head, tail, count, userInfo);
		        break;
			
			default:
				break;
		}

		cout << endl;
		system("cls");
		
	}while (choice != '8');
	
	
    return 0;
}
