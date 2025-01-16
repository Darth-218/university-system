#pragma once

#include "binary_tree_node.h"

template <typename T> class BinaryTree {
private:
  Node<T> *root;
  int size;

public:
  BinaryTree();

  bool isEmpty();

  int getSize();

  bool insert(T value);

  bool deleteNode(T value);

  void displayTree();

  void displayNode(Node<T> *root);
};

#include "../templates/binary_tree.tpp"
