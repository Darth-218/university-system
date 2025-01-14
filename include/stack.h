#include "single_node.h"
using namespace std;

template <typename T> class stack {
private:
  Node<T> *stack_top;
  int size;

public:
  stack();

  bool isEmpty();

  int getSize();

  bool push(T object);

  bool pop();

  T peek();

};
