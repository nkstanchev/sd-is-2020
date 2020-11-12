#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "bintree.h"
#include <cassert>
#include <algorithm>
#include <stack>
#include <queue>

template <class T>
BinTree<T>::BinTree():root(nullptr)
{

}

template <class T>
void BinTree<T>::add (const T &x, const char *trace)  
{
    if (root == nullptr)
    {
        assert (trace[0] == 0);
        root = new node(x,nullptr,nullptr);
        return;
    }

    assert (trace[0] != 0);

    BinTree<T>::node *current = root;

    while (trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        
        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        assert (current != nullptr);    
        ++trace;
    }

    if (trace[0] == 'L')
    {
        assert(current->left == nullptr);
        current->left = new node(x,nullptr,nullptr);
    } else if (trace[0] == 'R')
    {
        assert(current->right == nullptr);
        current->right = new node(x,nullptr,nullptr);
    } else 
    {
        assert (false);
    }



}

template <class T>
T BinTree<T>::get (const char *trace) const
{

    BinTree<T>::node *element = locate(trace);
    assert (element != nullptr);
    return element->data;

}

template <class T>
typename BinTree<T>::node* BinTree<T>::locate (const char *trace) const
{
    BinTree<T>::node *current = root;
    while (trace[0] != 0)
    {
        assert (current != nullptr);
        assert (trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        ++trace;
    }

    assert (current != nullptr);
    return current;
}

template <class T>
T& BinTree<T>::operator [](const char *trace)
{
    BinTree<T>::node *element = locate(trace);
    assert (element != nullptr);
    return element->data; 
}

template <class T>
void BinTree<T>::toDotty(std::ostream& out)
{
    out << "digraph G{\n";
    toDottyHelp(out, root);
    out << "}";
}

template <class T>
void BinTree<T>::toDottyHelp (std::ostream& out, node *current)
{
    if (current == nullptr)
    {
        return;
    }
    out << (long)current << "[label=\"" << current->data << "\"];\n";

    if (current->left != nullptr)
    {
        out << (long)current << "->" << (long)(current->left) << "[color=red];\n";
    } 
    if (current->right != nullptr)
    {
        out << (long)current << "->" << (long)(current->right) << "\n";
    }

    toDottyHelp (out, current->left);
    toDottyHelp (out, current->right);
}


template <class T>
bool BinTree<T>::member (const T& x)
{
    return memberHelp(x,root);
}

template <class T>
bool BinTree<T>::memberHelp (const T& x, node* current)
{
    if (current == nullptr)
    {
        return false;
    }

    return current->data == x ||
           memberHelp (x, current->left) ||
           memberHelp (x, current->right);

/*
    return current != nullptr &&   
                (current->data == x ||
                memberHelp (x, current->left) ||
                memberHelp (x, current->right));
*/
}

template <class T>
T BinTree<T>::sum ()
{
    return sumHelper(root);
}


template <class T>
T BinTree<T>::sumHelper (node* current)
{
    if (current == nullptr)
    {
        return 0;
    }

    return current->data +
           sumHelper(current->left) +
           sumHelper(current->right);
}

template <class T>
T BinTree<T>::max ()
{
    return maxHelper(root);
}


template <class T>
T BinTree<T>::maxHelper (node* current)
{
    if (current == nullptr)
    {
        return 0;
    }

    return std::max(current->data,std::max(maxHelper(current->left),maxHelper(current->right)));
}

template <class T>
T BinTree<T>::min ()
{
    return minHelper(root);
}

template <class T>
T BinTree<T>::minHelper (node* current)
{
    if (current->left == nullptr && current->right == nullptr)
    {
        return current->data;
    }
    if (current->left == nullptr) {
        return std::min(current->data,minHelper(current->right));
    }
    if (current->right == nullptr) {
        return std::min(current->data,minHelper(current->left));
    }
    return std::min(current->data,std::min(minHelper(current->left),minHelper(current->right)));
}

template <class T>
void BinTree<T>::printLeafs ()
{
    printLeafsHelper(root);
}

template <class T>
void BinTree<T>::printLeafsHelper (node* current)
{
    if (current->left == nullptr && current->right == nullptr)
    {
        std::cout << current->data << std::endl;
        return;
    }
    if (current->left == nullptr && current->right != nullptr) {
        printLeafsHelper(current->right);
    }
    else if (current->right == nullptr && current->left != nullptr) {
        printLeafsHelper(current->left);
    } else {
        printLeafsHelper(current->left);
        printLeafsHelper(current->right);
    }
}

template <class T>
T BinTree<T>::sumLeafs ()
{
    return sumLeafsHelper(root);
}

template <class T>
T BinTree<T>::sumLeafsHelper (node* current)
{
    if (current->left == nullptr && current->right == nullptr)
    {
        return current->data;
    }
    if (current->left == nullptr && current->right != nullptr) {
        return sumLeafsHelper(current->right);
    }
    else if (current->right == nullptr && current->left != nullptr) {
        return sumLeafsHelper(current->left);
    } else {
        return sumLeafsHelper(current->left) + sumLeafsHelper(current->right);
    }
}

template <class T>
void BinTree<T>::dfs ()
{
    return dfsHelper(root);
}

template <class T>
void BinTree<T>::dfsHelper (node* current)
{
    if (current == nullptr) {
        return;
    }
    std::cout << current->data << std::endl;
    dfsHelper(current->left);
    dfsHelper(current->right);    
}

template <class T>
void BinTree<T>::dfsIterative ()
{
    std::stack<node*> st;
    st.push(root);
    while(!st.empty()) {
        node* temp = st.top();
        st.pop();
        std::cout << temp->data << std::endl;
        if (temp->right != nullptr) st.push(temp->right);
        if (temp->left != nullptr) st.push(temp->left);
    }
}

template <class T>
void BinTree<T>::bfs ()
{
    std::queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        std::cout << temp->data << std::endl;
        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }
}

#endif