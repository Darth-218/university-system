#pragma once
#include "../include/stack.h"
using namespace std;

template <typename T> bool stack <T>::stack(){
 stack_top = NULL;
 size = 0;

}

template <typename T> bool stack <T>::isEmpty(){
    return stack_top == NULL;
}

template <typename T> int stack <T>::getSize(){
    return size;
}

template <typename T> bool stack <T>::push(T object){
    Node<T> *newNode = new Node<T>(object); 
    newNode ->next = stack_top;
    stack_top = newNode;
    size++;
    return true;
    }

template <typename T> bool stack <T>::pop(){
    if (isEmpty()){
        return false;
    }

    Node<T> *prev = stack_top;
    stack_top = stack_top ->next;
    delete prev;
    size--;
    return true;

}

template <typename T> T stack <T>::peek(){
    if (isEmpty()){
        return false;
    }
     return stack_top->object;
}
