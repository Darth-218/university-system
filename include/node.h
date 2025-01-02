#include <cstddef>

template <typename T> class Node {
public:
  T value;
  Node *right, *left;
  Node(T value) {
    this->value = value;
    this->right = this->left = NULL;
  }
};
