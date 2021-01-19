#include <iostream>
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data, Node* next = nullptr, Node* prev = nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
}; 
class LList {
    Node* first = nullptr;
    Node* last = nullptr;
    public:
    void insert_back(int data) {

        Node* newNode = new Node(data);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        } else {
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
    }
};
int main() {
    LList l;
    l.insert_back(1);
    l.insert_back(2);
    l.insert_back(3);
}