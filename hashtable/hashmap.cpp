#ifndef __HASHMAP_CPP
#define __HASHMAP_CPP

#include "hashmap.h"
#include <cassert>

template<class Keys, class Values>
HashMap<Keys,Values>::HashMap (size_t _size, std::function<size_t(const Keys&)> _h):size(_size),h(_h)
{
    table = new Entry*[size];
    for (int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }
}
template<class Keys, class Values>
HashMap<Keys,Values>::HashMap() {
    this->size = 0;
    table = new Entry*[0];
}
template<class Keys, class Values>
void HashMap<Keys,Values>::copy(const HashMap<Keys, Values>& other) {
    this->size = other.size;
    table = new Entry*[this->size];
    this->h = other.h;
    for (int i = 0; i < size; ++i)
    {
        if (other.table[i] != nullptr) {
            HashMap<Keys,Values>::Entry *otherCurr = other.table[i];
            HashMap<Keys,Values>::Entry *firstCopy = nullptr;
            HashMap<Keys,Values>::Entry *prevCopy = nullptr;
            while(otherCurr != nullptr) {
                // copy key, value and next node
                HashMap<Keys,Values>::Entry *copyCurr = new Entry();
                copyCurr->key = otherCurr->key;
                copyCurr->value = otherCurr->value;
                if (firstCopy == nullptr) {
                    firstCopy = copyCurr;
                }
                if (prevCopy != nullptr) {
                    prevCopy->next = copyCurr;
                }
                prevCopy = copyCurr;
                otherCurr = otherCurr->next;
            }
            table[i] = firstCopy;
        } else {
            table[i] = nullptr;
        }
    }
}

template<class Keys, class Values>
void HashMap<Keys,Values>::del() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr) {
            HashMap<Keys,Values>::Entry *curr = table[i];
            HashMap<Keys,Values>::Entry *currNext = nullptr;
            while(curr != nullptr) {
                currNext = curr->next;
                delete curr;
                curr = currNext;
            }
        }
    }
    delete[] table;
}

template<class Keys, class Values>
HashMap<Keys,Values>::HashMap(const HashMap<Keys, Values>& other) {
    this->copy(other);
}
template<class Keys, class Values>
HashMap<Keys,Values>& HashMap<Keys,Values>::operator=(const HashMap<Keys, Values>& other) {
    if(this != &other) {
        del();
        copy(other);    
    }
    return *this;
}
template<class Keys, class Values>
HashMap<Keys,Values>::~HashMap() {
    del();
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Entry *HashMap<Keys,Values>::locate(size_t index, const Keys &key) const
{
    HashMap<Keys,Values>::Entry *current =  table[index];
    while (current != nullptr && current->key != key)
    {
        current = current->next;    
    }
    return current;
}

template<class Keys, class Values>
Values HashMap<Keys,Values>::operator[](const Keys &key) const
{

    typename HashMap<Keys,Values>::Entry *current =  locate(h(key)%size,key);
    assert (current != nullptr);

    return current->value;

}

template<class Keys, class Values>
Values& HashMap<Keys,Values>::operator[](const Keys &key)
{
    size_t index = h(key)%size;
    
    typename HashMap<Keys,Values>::Entry *current = locate(index,key);

    if (current == nullptr)
    {
        current = table[index] = new HashMap<Keys,Values>::Entry {key,Values(),table[index]};
    }

    return current->value;
    
}

template<class Keys, class Values>
bool HashMap<Keys,Values>::hasKey (const Keys &key) const
{
    return locate(h(key)%size,key) != nullptr;
}

template<class Keys, class Values>
HashMap<Keys,Values>::Iterator::Iterator(Entry **_table, size_t _size):table(_table), size(_size)
{
    currentRow = 0;
    currentColumn = nullptr;

    if (table == nullptr)
    {
        return;
    }

    currentColumn = table[currentRow];
    while (currentRow < size && currentColumn == nullptr)
    {
        ++currentRow;
        currentColumn = table[currentRow];
    }
}

template<class Keys, class Values>
Keys HashMap<Keys,Values>::Iterator::operator *()
{
    assert(currentColumn != nullptr);
    return currentColumn->key;
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Iterator& HashMap<Keys,Values>::Iterator::operator ++()
{
    assert(currentColumn != nullptr);
    currentColumn = currentColumn->next;

    if(currentColumn == nullptr)
    {
        ++currentRow;
        while (currentRow < size && currentColumn == nullptr)
        {
            currentColumn = table[currentRow];
            ++currentRow;
            
        }        
    }
    return *this;
}

template<class Keys, class Values>
bool HashMap<Keys,Values>::Iterator::operator != (const typename HashMap<Keys,Values>::Iterator &other) const
{
    return currentColumn != other.currentColumn;
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::begin() const
{
    return typename HashMap<Keys,Values>::Iterator(table,size);
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::end() const
{
    return typename HashMap<Keys,Values>::Iterator(nullptr,size);
}

#endif