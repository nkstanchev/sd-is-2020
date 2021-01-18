#ifndef __TRIE_H
#define __TRIE_H

#include <unordered_map>
#include <string>
#include <iostream>


template<class Values>
class TrieMap
{
    public:

    TrieMap();
    TrieMap(const TrieMap&);
    TrieMap& operator=(const TrieMap&);
    ~TrieMap();

    Values operator[](const std::string&) const;
    Values& operator[](const std::string&);

    bool hasKey(const std::string&) const;
    void remove(const std::string&);

    //opearator =
    //TrieMap(const TrieMap&);

    void exportToDot(std::ostream&) const;

    private:

    struct Node
    {
        Values* value;
        std::unordered_map<char,Node*> children;
    };

    Node *root;
    Node *locate(const std::string key) const;
    void copy(Node* current, Node* otherCurrent);
    void del(Node* current);
    void exportToDot(std::ostream&, Node*) const;
};



#endif