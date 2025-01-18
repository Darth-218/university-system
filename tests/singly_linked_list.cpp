#include "../include/singly_linked_list.h"

int main() {
    SinglyLinkedList<int> ll;

    cout << "is empty: " << ll.isEmpty() << endl;

    cout << "inserting 9 at index 0: " << ll.insert(9, 0) << endl;
    ll.display();

    cout << "appending 1: " << ll.append(1) << endl;
    ll.display();

    cout << "pushing 0: " << ll.push(0) << endl;
    ll.display();

    cout << "inserting 2 at index 1: " << ll.insert(2, 1) << endl;
    ll.display();

    cout << "inserting 7 at index 3: " << ll.insert(7, 3) << endl;
    ll.display();

    cout << "inserting 8 at index 3: " << ll.insert(8, 3) << endl;
    ll.display();

    cout << "deleting index 4: " << ll.deleteNode(4) << endl;
    ll.display();

    cout << "deleting index 0: " << ll.deleteNode(0) << endl;
    ll.display();

    cout << "deleting index 1: " << ll.deleteNode(1) << endl;
    ll.display();

    return 0;
}