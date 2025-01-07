#include "../include/binary_tree.h"

int main() {

  BinaryTree<int> tree;

  tree.insert(5);
  tree.insert(6);
  tree.insert(3);
  tree.insert(2);
  tree.insert(4);
  tree.insert(7);

  std::cout << tree << std::endl;
}
