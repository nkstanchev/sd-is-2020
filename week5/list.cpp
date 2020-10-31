#ifndef __LLIST_CPP
#define __LLIST_CPP

#include <exception>
#include <stdexcept>
#include "list.h"

template<class T>
void LList<T>::copy(const LList<T>& other) {
    typename LList<T>::Node* curr = other.first;
    typename LList<T>::Node* temp;
    typename LList<T>::Node* prevTemp = nullptr;
    while (curr != nullptr) {
        temp = new typename LList<T>::Node(curr->data);
        if (prevTemp) {
            prevTemp->next = temp;
        }
        else {
            this->first = temp;
        }
        temp->prev = prevTemp;
        prevTemp = temp;
        curr = curr->next;
    }
    this->last = temp;
    this->len = other.len;
}
template<class T>
void LList<T>::del() {
    LList<T>::Node* curr = this->first;
    LList<T>::Node* temp = nullptr;
    while (curr != nullptr) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    this->first = nullptr;
    this->last = nullptr;
}
template<class T>
LList<T>::LList() {
    this->first = nullptr;
    this->last = nullptr;
    this->len = 0;
}
template<class T>
LList<T>::LList(const LList<T>& other) {
    copy(other);
}
template<class T>
LList<T>& LList<T>::operator=(const LList<T>& other) {
    if (this != &other) {
        del();
        copy(other);
    }
    return *this;
}
template<class T>
LList<T>::~LList() {
    del();
}
template<class T>
void LList<T>::insert_back(T data)
{
    typename LList<T>::Node* newNode = new typename LList<T>::Node(data);
    if (this->first == nullptr) {
        this->first = newNode;
        this->last = newNode;
    }
    else {
        newNode->prev = this->last;
        this->last->next = newNode;
        this->last = newNode;
    }
    this->len++;
}
template<class T>
void LList<T>::insert_front(T data)
{
    typename LList<T>::Node* newNode = new typename LList<T>::Node(data);
    newNode->next = this->first;
    if (this->first != nullptr) {
        // ako ne e prazen spisak
        this->first->prev = newNode;
        this->first = newNode;
    }
    else {
        // ako e prazen spisak
        this->first = newNode;
        this->last = this->first;
    }
    this->len++;
}
// premahnni posledniq element
template<class T>
void LList<T>::pop_back() {
    typename LList<T>::Node* temp = this->last;
    if (this->last == nullptr) {
        throw std::underflow_error("Trying to remove when no elements");
    }
    else if (this->first == this->last) {
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        this->last = this->last->prev;
        this->last->next = nullptr;
        // optional step
        temp->prev = nullptr;
    }
    delete temp;
    this->len--;
}
// premahni pyrviq element
template<class T>
void LList<T>::pop_front() {
    if (this->first == nullptr) {
        throw std::underflow_error("Trying to remove when no elements");
    }
    else if (this->first == this->last) {
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        typename LList<T>::Node* temp = this->first;
        this->first = this->first->next;
        this->first->prev = nullptr;
        delete temp;
    }
    this->len--;
}
template<class T>
LList<T>::Iterator::Iterator(typename LList<T>::Node* curr, LList<T>* list) {
    this->curr = curr;
    this->list = list;
}
template<class T>
typename LList<T>::Iterator& LList<T>::Iterator::operator++() {
    if (this->curr == nullptr)
    {
        throw std::out_of_range("No more elements in list.");
    }
    this->curr = this->curr->next;
    return *this;
}
template<class T>
typename LList<T>::Iterator& LList<T>::Iterator::operator--() {
    if (this->curr == nullptr)
    {
        if (this->list->first == nullptr)
        {
            throw std::out_of_range("List is empty");
        } else
        {
            this->curr = this->list->last;
        }
    } else
    {
        this->curr = this->curr->prev;
    }
    return *this;
}
template<class T>
int LList<T>::Iterator::operator*() {
    return curr->data;
}
template<class T>
int LList<T>::Iterator::operator!=(const LList<T>::Iterator& other) {
    return curr != other.curr;
}
template<class T>
typename LList<T>::Iterator LList<T>::begin() {
    return Iterator(this->first, this);
}
template<class T>
typename LList<T>::Iterator LList<T>::end() {
    return Iterator(nullptr, this);
}
template<class T>
int LList<T>::length() {
    return this->len;
}
#endif