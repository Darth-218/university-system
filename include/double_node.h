#pragma once

#include "includes.h"

template <typename T> class DNode {
public:
  T value;
  DNode *prev;
  DNode *next;
  DNode(T value) {
    this->value = value;
    prev = NULL;
    next = NULL;
  }
};
