#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "node.h"
#include <iostream>

template <typename T> class BinaryTree {
private:
  Node<T> *root;

public:
  BinaryTree();

  bool isEmpty();

  bool insert(T value);

  bool deleteNode(T value);

  void display();

  void traverse(Node<T> *root);
};

#include "../templates/binary_tree.tpp"

#endif
