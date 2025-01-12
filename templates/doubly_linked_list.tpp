#pragma once

#include "../include/doubly_linked_list.h"

using namespace std;

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
}

template <typename T> bool DoublyLinkedList<T>::isEmpty() {
  return head == NULL;
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
  return true;
}

// FIX: Split case 2 into both cases.
// FIX: Refactor, Case one and `append` under case zero to improve best case
// runtime
template <typename T> bool DoublyLinkedList<T>::insert(T value, int position) {
  Node<T> *newNode = new Node<T>(value);
  Node<T> *tmp = head;
  int current_position = 0;

  // case 0: position doesn't exist
  if (position < 0) {
    return false;
  }

  while (tmp != NULL && current_position < position - 1) {
    tmp = tmp->next;
    current_position++;
  }

  // case 1: position is 0
  if (position == 0) {
    push(value);
    return true;
  }

  // case 2: position is at middle or end.
  if (tmp != NULL) {
    newNode->next = tmp->next;
    // check if node is at the end
    if (tmp->next != NULL) {
      tmp->next->prev = newNode;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    return true;
  }
}

template <typename T> bool DoublyLinkedList<T>::removeHead() {
  // case 0: list is empty
  if (head == NULL) {
    return false;
  }

  // case 1: list is not empty
  head = head->next;
  head->prev = NULL;
  return true;
}

template <typename T> bool DoublyLinkedList<T>::removeTail() {
  // case 0: list is empty
  // FIX: Use the function?
  if (head == NULL) {
    return false;
  }

  // case 1: list is not empty
  tail = tail->prev;
  tail->next = NULL;
  return true;
}

// FIX: Check if the list is empty first.
// FIX: Actually delete the nodes.
template <typename T> bool DoublyLinkedList<T>::deleteNode(T value) {
  Node<T> *tmp = head;
  while (tmp != NULL) {
    if (tmp->value == value) {
      // case 1: node is at head
      if (tmp == head) {
        removeHead();
        return true;
      }

      // case 2: node is at tail
      // TEST:
      if (tmp == tail) {
        removeTail();
        return true;
      }

      // case 3: node is in the middle
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
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
