#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "bintree.h"
#include <cassert>

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
           sum(current->left) +
           sum(current->right);
}

template<class T>
bool BinTree<T>::operator == (const BinTree<T> &other)
{
    return equaltrees (root, other.root);
}


template<class T>
bool BinTree<T>::equaltrees (node *root1, node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return root2 == nullptr && root1 == nullptr;
    }

    return root1->data == root2->data &&
           equaltrees (root1->left, root2->left) &&
           equaltrees (root1->right, root2->right);

}


template<class T>
void BinTree<T>::toScheme(std::ostream &out)
{
    toScheme (out, root);
}

template<class T>
void BinTree<T>::toScheme (std::ostream &out, BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        out << "()";
        return;
    }

    out << '('
        << current->data
        << " ";

    toScheme (out, current->left);

    out << " ";

    toScheme (out, current->right);

    out << ")";
}


template<class T>
void BinTree<T>::fromScheme(std::istream &in)
{
    clear (root);

    root = readSchemeRec (in);

}

template<class T>
typename BinTree<T>::node* BinTree<T>::readSchemeRec (std::istream &in)
{
  
    char c;
    in >> c; 
    assert (c == '(');

    if (in.peek() == ')')
    {//празно дърво
        in.get();
        return nullptr;
    }

    T value;
    in >> value;

    //(<value>  <Tree> <Tree>)
    //        /|\.
    //         |

    BinTree<T>::node *left=readSchemeRec (in);

    //(<value>  <Tree> <Tree>)
    //               /|\.
    //                |


    BinTree<T>::node *right=readSchemeRec (in);

    //(<value>  <Tree> <Tree> )
    //                      /|\.
    //                       |

    in >> c;
    assert (c == ')');

    return new node(value,left,right);
}

template<class T>
void BinTree<T>::clear(BinTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }   

   clear (current->left);
   clear (current->right);
   delete current; 

}

template<class T>
void BinTree<T>::insertOrdered (const T &x)
{
    insertOrdered (x,root);
}


template<class T>
void BinTree<T>::insertOrdered (const T& x, node*& current)
{
    if (current == nullptr) {
        current = new node(x, nullptr, nullptr);
        return;
    }
    if (x < current->data) {
        insertOrdered(x, current->left);
    } else {
        insertOrdered(x, current->right);
    }
}
template<class T>
int BinTree<T>::sumParentNodesWithChildX(int x) {
    int sum = 0;
    return sumParentNodesWithChildXHelper(x, root, sum);
}
template<class T>
int BinTree<T>::sumParentNodesWithChildXHelper(int x, node* curr, int sum) {
    if (curr == nullptr) {
        return 0;
    }
    if ((curr->left && curr->left->data == x) || (curr->right && curr->right->data == x)) {
        return curr->data
                + sumParentNodesWithChildXHelper(x, curr->left, sum) 
                + sumParentNodesWithChildXHelper(x, curr->right, sum);
    }
    return sumParentNodesWithChildXHelper(x, curr->left, sum) + sumParentNodesWithChildXHelper(x, curr->right, sum);
}
template<class T>
bool BinTree<T>::isFullBinaryTree() {
    return isFullBinaryTreeHelper(root);
}

template<class T>
bool BinTree<T>::isFullBinaryTreeHelper(node* curr) {
    if (curr == nullptr) {
        return true;
    }
    if (!curr->left && !curr->right) {
        return true;
    }
    if (curr->left && curr->right) {
        return isFullBinaryTreeHelper(curr->left) && isFullBinaryTreeHelper(curr->right);
    }
    return false;    
}
template<class T>
bool BinTree<T>::isBST() {
    return isBSTHelper(root, INT_MIN, INT_MAX);
}
template<class T>
bool BinTree<T>::isBSTHelper(node* curr, int min, int max) {
    if (curr == nullptr) {
        return true;
    }
    if (curr->data < min || curr->data > max) {
        return false;
    }
    return isBSTHelper(curr->left, min, curr->data) &&
           isBSTHelper(curr->right, curr->data, max);
}
template<class T>
bool BinTree<T>::areMirrorHelper(node* a, node* b) { 
    if (a == nullptr && b == nullptr) 
        return true; 
  
    if (a == nullptr || b == nullptr) 
        return false; 

    return  a->data == b->data && 
            areMirrorHelper(a->left, b->right) && 
            areMirrorHelper(a->right, b->left); 
} 
template<class T>
bool BinTree<T>::areMirror(BinTree<T>& other) { 
    return areMirrorHelper(root, other.root);
}
template<class T>
typename BinTree<T>::node* BinTree<T>::copyHelper(node *orgTree){
    if(orgTree != nullptr){
        node* temp = new node(orgTree->data, nullptr, nullptr);
        temp->left = copyHelper(orgTree->left);
        temp->right = copyHelper(orgTree->right);
        return temp;
    }
    return nullptr;
}
template<class T>
void BinTree<T>::copy(BinTree<T>& other){
    this->root = copyHelper(other.root);
}
#endif