#pragma once

#include "binary_tree_node.h"
#include "includes.h"

template <typename T> class BinaryTree {
private:
  TNode<T> *root;
  int size;

public:
  BinaryTree();

  bool isEmpty();

  int getSize();

  bool insert(T value);

  bool deleteNode(T value);

  void displayTree();

  void displayNode(TNode<T> *root);
};

#include "../templates/binary_tree.tpp"
