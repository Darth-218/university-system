#include <cstddef>

template <typename T> class Node {
public:
  T value;
  Node *right, *left;
  bool is_root, is_right, is_left;
  Node(T value) {
    this->value = value;
    this->right = this->left = NULL;
    this->is_root = this->is_right = this->is_left = false;
  }
};
