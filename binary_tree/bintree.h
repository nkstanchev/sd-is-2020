#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
class BinTree
{
    public:

    BinTree();

    //Вмъква ново листо в дървото на дадена позиция. Не позволява 
    //изменяне на съшествуващи елементи
    void add (const T&, const char*);
    T get (const char*) const;
    T& operator [](const char*);
    void toDotty(std::ostream& out);

    bool member (const T& x);
    T sum ();
    T max();
    T min();
    void printLeafs();
    T sumLeafs();
    void dfs();
    void dfsIterative();
    void bfs();

    private:
    struct node
    {
        T data;
        node *left, *right;
        node(T data, node *left, node *right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };

    void toDottyHelp (std::ostream& out, node*);
    node* locate (const char*) const;
    bool memberHelp (const T&, node*);
    T sumHelper (node*);
    T maxHelper (node*);
    T minHelper (node*);
    void printLeafsHelper(node*);
    T sumLeafsHelper(node*);
    void dfsHelper(node*);

    node *root;
};
#include "bintree.cpp"
#endif