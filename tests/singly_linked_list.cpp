#include "../include/singly_linked_list.h"

int main() {
    SinglyLinkedList<int> ll;
    ll.append(66);
    ll.display();
    ll.push(33);
    ll.insert(22, 3);
    ll.display();
    ll.deleteNode(1);
    ll.removeHead();
    ll.removeNode(0);
    ll.append(90);

    return 0;
}