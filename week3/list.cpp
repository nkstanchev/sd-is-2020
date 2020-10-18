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
    void insert_back(int data)
    {
        Node* newNode = new Node(data);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }
        else {
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
    }

    void insert_front(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = first;
        if (first != nullptr) {
            // ako ne e prazen spisak
            first->prev = newNode;
            first = newNode;
        }
        else {
            // ako e prazen spisak
            first = newNode;
            last = first;
        }
    }
    // premahnni posledniq element
    void pop_back() {
        Node* temp = last;
        if (last == nullptr) {
            return;
        }
        else if (first == last) {
            first = nullptr;
            last = nullptr;
        }
        else {
            last = last->prev;
            last->next = nullptr;
            // optional step
            temp->prev = nullptr;
        }
        delete temp;
    }
    // premahni pyrviq element
    void pop_front() {
        if (first == nullptr) {
            return;
        }
        else if (first == last) {
            delete first;
            first = nullptr;
            last = nullptr;
        }
        else {
            Node* temp = first;
            first = first->next;
            first->prev = nullptr;
            delete temp;
        }
    }
    void print() {
        Node* curr = first;
        while (curr != nullptr) { // curr->next ako iskame sled while curr da e posledniq element
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

class Stack : public LList {
public:
    void add(int data) {
        this->insert_back(data);
    }
    void remove() {
        this->pop_back();
    }
};

class Queue : public LList {
public:
    void add(int data) {
        this->insert_front(data);
    }
    void remove() {
        this->pop_back();
    }
};

int main() {
    Queue l;
    l.add(2);
    l.add(1);
    /*l.insert_back(1);
    l.insert_back(2);
    l.insert_back(3);*/
}