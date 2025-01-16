#include "../include/binary_tree.h"

int main() {

  BinaryTree<int> tree;

  std::cout << "Checking if the tree is empty: " << tree.isEmpty() << std::endl;

  tree.insert(5);
  tree.insert(6);
  tree.insert(3);
  tree.insert(2);
  tree.insert(4);
  tree.insert(7);

  std::cout << "Getting the tree size after insertion (5, 6, 3, 2, 4, 7): "
            << tree.getSize() << std::endl;

  std::cout << "Checking if the tree is empty: " << tree.isEmpty() << std::endl;

  std::cout << "Printing the tree: " << tree << std::endl;

  tree.deleteNode(3);

  std::cout << "Printing the tree after deletion (3): " << tree << std::endl;

  tree.deleteNode(2);

  std::cout << "Printing the tree after deletion (2): " << tree << std::endl;

  tree.deleteNode(4);

  std::cout << "Printing the tree after deletion (4): " << tree << std::endl;
}
