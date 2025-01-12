#include "../include/singly_linked_list.h"

int main() {
    SinglyLinkedList<int> ll;
    
    std::cout << ll << std::endl;

    /// instead of
    ll.display();
    
    return 0;
}