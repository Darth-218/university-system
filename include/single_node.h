
#include <iostream>
using namespace std;
template <typename T> class SingleNode {
public:
    T value;
    SingleNode* prev;
    SingleNode* next;
    SingleNode(T value) {
        this->value = value;
        next = NULL;
    }
};
