#pragma once

#include "../include/doubly_linked_list.h"

using namespace std;

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
  length = 0;
}

template <typename T> bool DoublyLinkedList<T>::isEmpty() {
  return head == NULL;
}

template <typename T> int DoublyLinkedList<T>::getLength() {
  return length;
}

template <typename T> bool DoublyLinkedList<T>::push(T value) {

  Node<T> *newNode = new Node<T>(value);
  // case 1: List is empty.
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }
  // case 2: List is not empty.
  else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  length++;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::append(T value) {

  Node<T> *newNode = new Node<T>(value);
  // case 1: List is empty.
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }
  // case 2: List is not empty.
  else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  length++;
  return true;
}

// FIX: Split case 2 into both cases. (D)
// FIX: Refactor, Case one and `append` under case zero to improve best case (D)
// runtime
template <typename T> bool DoublyLinkedList<T>::insert(T value, int position) {
  Node<T> *newNode = new Node<T>(value);
  Node<T> *tmp = head;
  int current_position = 0;

  // case 0: position doesn't exist
  if (position < 0) {
    return false;
  }
  if (position == 0) {
    push(value);
    return true;
  }
  if (position == length) {
    append(value);
    return true;
  }

  // case 1: position is at middle.
  while (tmp != NULL && current_position < position - 1) {
    tmp = tmp->next;
    current_position++;
  }
  if (tmp != NULL) {
    newNode->next = tmp->next;
    // Check if there is a node after
    if (tmp->next != NULL) {
      tmp->next->prev = newNode;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    length++;
    return true;
  }
  return false;
}

template <typename T> bool DoublyLinkedList<T>::removeHead() {
  // case 0: list is empty
  if (head == NULL) {
    return false;
  }

  // case 1: list is not empty
  head = head->next;
  head->prev = NULL;
  length--;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::removeTail() {
  // case 0: list is empty
  // FIX: Use the function? (D)
  if (head == NULL) {
    return false;
  }

  // case 1: list is not empty
  tail = tail->prev;
  tail->next = NULL;
  length--;
  return true;
}

// FIX: Check if the list is empty first.(D)
// FIX: Actually delete the nodes. (D)
template <typename T> bool DoublyLinkedList<T>::deleteNode(T value) {
  Node<T> *tmp = head;

  // check if list is empty first
  if (head == NULL) {
    return false;
  }

  while (tmp != NULL) {
    if (tmp->value == value) {
      // case 1: node is at head
      if (tmp == head) {
        removeHead();
        return true;
      }

      // case 2: node is at tail
      // TEST: (D)
      if (tmp == tail) {
        removeTail();
        return true;
      }

      // case 3: node is in the middle
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
      delete tmp;
      length--;
      return true;
    }
    tmp = tmp->next;
  }
  return false;
}

// TODO: Overload the "<<" operator to use this function automatically.
template <typename T> void DoublyLinkedList<T>::display() {
  if (head == NULL) {
    cout << "The list is empty." << endl;
    return;
  }

  Node<T> *tmp = head;
  cout << "List: ";
  while (tmp != NULL) {
    cout << tmp->value << " ";
    tmp = tmp->next;
  }
  cout << endl;
}
