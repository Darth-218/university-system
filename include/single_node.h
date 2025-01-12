#include <iostream>
#define NULL 0

using namespace std;
template <typename T> class Node {
public:
    T value;
    Node* next;
    Node(T value) {
        this->value = value;
        next = NULL;
    }
};
