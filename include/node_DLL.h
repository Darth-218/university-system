#include <iostream>
using namespace std;

template <typename T> class Node {
public:
  T value;
  Node *prev;
  Node *next;
  Node(T value) {
    this->value = value;
    prev = NULL;
    next = NULL;
  }
};
