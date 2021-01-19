#ifndef __TRIEMAP_CPP
#define __TRIEMAP_CPP    

#include "triemap.h"
#include <stack>
#include <cassert>

template<class Values>
TrieMap<Values>::TrieMap()
{
    root = new TrieMap<Values>::Node {nullptr};
}
template<class Values>
void TrieMap<Values>::copy(Node* current, Node* otherCurrent) {
    if (otherCurrent->value != nullptr) {
        current->value = new Values(*otherCurrent->value);
    }
    for (auto c : otherCurrent->children) {
        current->children[c.first] = new Node{};
        copy(current->children[c.first], c.second);
    }
}

template<class Values>
TrieMap<Values>::TrieMap(const TrieMap& other) : TrieMap() {
    copy(root, other.root);  
}
template<class Values>
TrieMap<Values>& TrieMap<Values>::operator=(const TrieMap& other) {
    if (this != &other) {
        copy(root, other.root);
    }
    return *this;
}

template<class Values>
void TrieMap<Values>::del(Node* current) {
    for (auto c : current->children) {
        del(current->children[c.first]);
    }
    delete current;
}

template<class Values>
TrieMap<Values>::~TrieMap() {
    del(root);
} 

template<class Values>
Values TrieMap<Values>::operator[](const std::string& key) const
{
    assert (root != nullptr);
    typename TrieMap<Values>::Node* node = locate(key);
    assert(node != nullptr);
    assert(node->value != nullptr);

    return *(node->value);

}

template<class Values>
typename TrieMap<Values>::Node* TrieMap<Values>::locate(const std::string key) const
{
    assert (root != nullptr);
    if (root == nullptr)
    {
        return nullptr;
    }
    
    typename TrieMap<Values>::Node* current = root;
    
    for (char c : key)
    {
        if (current->children.count(c) > 0)
        {
            current = current->children[c];
        } else 
        {
            return nullptr;
        }
    }

    return current;
}

template<class Values>
Values& TrieMap<Values>::operator[](const std::string& key) 
{
    assert (root != nullptr);
    typename TrieMap<Values>::Node* node = locate(key);

    if (node != nullptr)
    {
        if (node->value == nullptr)
        {
            node->value = new Values();
        }
        return *(node->value);
    } else
    {
        typename TrieMap<Values>::Node* current = root; 
        size_t iletter = 0;

        while (current->children.count(key[iletter]) > 0)
        {
            assert(iletter < key.length());
            current = current->children[key[iletter]];
            ++iletter;
        }

        for (;iletter < key.length(); ++iletter)
        {
            current->children[key[iletter]] = new Node{nullptr};
            current = current->children[key[iletter]];
        }

        current->value = new Values();
        return *(current->value);

    }

}

template<class Values>
bool TrieMap<Values>::hasKey(const std::string &key) const
{
    typename TrieMap<Values>::Node* node = locate(key);
    return node != nullptr && node->value != nullptr;   
}


template<class Values>
void TrieMap<Values>::exportToDot(std::ostream &out) const
{
    out << "digraph G{\n";
    exportToDot(out,root);
    out << "}";
}

template<class Values>
void TrieMap<Values>::exportToDot(std::ostream &out, typename TrieMap<Values>::Node* root) const
{

    out << (long)root << "[label=\"";
    if (root->value != nullptr)
    {
        out << *(root->value);
    } else
    {
        out << "_";
    }
    out << "\"];\n";

    for (auto child : root->children)
    {
        //аз -> дете [label="<буква>"]
        out << (long)root 
            << "->" 
            << (long)(child.second) 
            << "[label=\""
            << child.first
            << "\"];\n";

        exportToDot(out, child.second);        
    }
    

}
template<class Values>
void TrieMap<Values>::remove(const std::string& key) {
    assert (root != nullptr);
    if (root == nullptr)
    {
        throw "key not found";
    }
    typename TrieMap<Values>::Node* current = root;
    typename TrieMap<Values>::Node* prev = root;
    typename TrieMap<Values>::Node* prevStack = root;
    char prevStackLetter;
    char prevLetter;
    std::stack<Node*> path;
    for (char c : key)
    {
        if (current->children.count(c) > 0)
        {
            if (current->children.size() == 1 && current != root && current->value == nullptr) {
                path.push(current);
            } else {
                while(!path.empty()) { 
                    path.pop(); 
                }
                prevStack = current;
                prevStackLetter = c;
            }
            prevLetter = c;
            prev = current;
            current = current->children[c];
        } else 
        {
            throw "key not found";
        }
    }
    if (!current) {
        throw "key not found";
    } else if (current->children.size() == 0) {
        while (!path.empty()) {
            Node* currentPath = path.top();
            path.pop();
            delete currentPath;
        }
        prevStack->children.erase(prevStackLetter);
    } else if (current->children.size() > 0) {
        current->value = nullptr;
    }
}

#endif