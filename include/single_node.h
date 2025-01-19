#pragma once

#include "includes.h"

template <typename T> class SNode {
public:
  T value;
  SNode *next;
  SNode(T value) {
    this->value = value;
    next = NULL;
  }
};
