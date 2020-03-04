#include "UnorderedLinkedLists.h"

int main() {

    system("cls");
	
	char choice;
	
	do {
		
		cout << "\n\t\t-----[ LINKED LIST STUFF ]-----\n\n";
		cout << "[1] initializeList\n";
		cout << "[2] isEmptyList\n";
		cout << "[3] print\n";
		cout << "[4] destroyList\n";
		cout << "[5] insertList\n";
		cout << "[6] ight imma head out\n\n";
		
		
		choice = GetChoice(1, 6);
		cout << endl;
		
		switch (choice) {
			
			case '1':
				cout << "initializeList call \n\n";
				break;
			
			case '2':
				cout << "isEmptyList call\n\n";
				break;
				
			case '3':
				cout << "print call\n\n";
				break;
				
			case '4':
				cout << "destroyList call\n\n";
				break;
				
			case '5':
				cout << "insertList call \n\n";
				break;
			
			default:
				break;
		}
		
		cout << endl;
		system("pause");
		system("cls");
		
	}while (choice != '6');
	
	
    return 0;
}
