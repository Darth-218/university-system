#pragma once

#include <iostream>
#include "node_DLL.h"
using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
    Node<T> *head, *tail;

public:
    DoubleLinkedList();

    bool isEmpty();

    bool append(T value);

    bool insert(T value, int position);

    bool push(T value);

    bool removeHead();

    bool removeNode();

    bool removeTail();

    bool deleteNode();

    void display();
};