#include <iostream>

template <class T>
struct TernTreeNode {
    T data;
    TernTreeNode<T> *left, *middle, *right;
    TernTreeNode(T data, TernTreeNode<T> *left = nullptr, TernTreeNode<T> *middle = nullptr, 
    TernTreeNode<T> *right = nullptr) {
        this->data = data;
        this->left = left;
        this->middle = middle;
        this->right = right;
    }
};
template <class T>
TernTreeNode<T>* createTree(unsigned int h) {
    if (h == 0) {
        return nullptr;
    }
    // return TernTreeNode<T>(h, createTree<T>(h-1), createTree<T>(h-1), createTree<T>(h-1));
    TernTreeNode<T> *node = new TernTreeNode<T>(h);
    node->left = createTree<T>(h-1);
    node->middle = createTree<T>(h-1);
    node->right = createTree<T>(h-1);
    return node;
}

struct ListNode {
    int data;
    ListNode *prev, *next;
    ListNode(int data , ListNode *prev = nullptr, ListNode *next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

ListNode* reverseAfterK(ListNode *root, unsigned int k) {
    if (root == nullptr) return nullptr;
    ListNode *curr = root;
    for(int i=0; i < k-1; i++) {
        if (curr == nullptr) return nullptr;
        curr = curr->next;
    }
    // cut lists after k
    ListNode *lastOriginal = curr;
    curr = curr->next;
    lastOriginal->next = nullptr;
    curr->prev = nullptr;

    // reverse
    ListNode *prev = nullptr, *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    // connect them again
    lastOriginal->next = prev;
    prev->prev = lastOriginal;
    // 1-2-3-4-5-6
    // 1-2-3-6-5-4
    return root;

}

int main() {
    TernTreeNode<unsigned int> *res = createTree<unsigned int>(3);
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    l1.next = &l2;
    l2.prev = &l1;
    l2.next = &l3;
    l3.prev = &l2;
    l3.next = &l4;
    l4.prev = &l3;
    l4.next = &l5;
    l5.prev = &l4;
    l5.next = &l6;
    ListNode *res2 = reverseAfterK(&l1,3);
    return 0;
}