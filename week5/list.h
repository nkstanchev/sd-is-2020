#ifndef __LLIST_H
#define __LLIST_H
template<class T>
class LList {
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T data, Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        };
    };
    void copy(const LList& other);
    void del();
    Node* first;
    Node* last;
    int len;
    public:
    LList();
    LList(const LList& other);
    LList& operator=(const LList& other);
    ~LList();
    void insert_front(T);
    void insert_back(T);
    void pop_back();
    void pop_front();
    class Iterator {
        Node* curr;
        LList *list;
        public:
        Iterator(Node* curr, LList* list);
        Iterator& operator++();
        Iterator& operator--();
        int operator*();
        int operator!=(const Iterator& other);
    };
    Iterator begin();
    Iterator end();
    int length();
};
#include "list.cpp"
#endif