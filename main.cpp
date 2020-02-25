#include "UnorderedLinkedLists.h"

int main() {

    system("cls");

    nodeType *head;
    nodeType *tail;
    int userElements;
    int count;
    int userData;

    // create the empty linked list with a head and tail to same obj
    initLinkedList(head, tail, count);


    // obtain user input and stuff it into new nodes of the linked list
    cout << "How many elements would you like to enter into the int linked list? ";
    cin  >> userElements;

    for (int i = 0; i < userElements; i ++) {
        cout << "Enter an integer: ";
        cin  >> userData;
        insertLinkedList(head, tail, count, userData);
    }

    // output contents of the linked list
    cout << "\nContents of linked list: \n";
    printLinkedList(head, tail);


    system("pause");
    return 0;
}
