#pragma once

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

  void displayTree();

  void displayNode(Node<T> *root);
};

#include "../templates/binary_tree.tpp"
