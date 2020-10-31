#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"
template<class T>
void Stack<T>::add(T data) {
    this->insert_back(data);
}
template<class T>
void Stack<T>::remove() {
    this->pop_back();
}
template<class T>
bool Stack<T>::empty() {
    return this->length() == 0;
}
#endif