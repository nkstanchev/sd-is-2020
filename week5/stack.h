#include "list.h"
#ifndef __STACK_H
#define __STACK_H
template<class T>
class Stack : public LList<T> {
public:
    void add(T data);
    void remove();
    bool empty();
};
#include "stack.cpp"
#endif