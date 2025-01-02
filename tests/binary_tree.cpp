#include "../include/binary_tree.h"

int main() {

  BinaryTree<int> tree;

  for (int i = 1; i != 5; tree.insert(i), i++)
    ;

  tree.deleteNode(3);

  tree.display();
}
