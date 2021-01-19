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
    void copy(const LList& other) {
        Node* curr = other.first;
        Node* temp;
        Node* prevTemp = nullptr;
        while (curr != nullptr) {
            temp = new Node(curr->data);
            if (prevTemp) {
                prevTemp->next = temp;
            }
            else {
                this->first = temp;
            }
            temp->prev = prevTemp;
            prevTemp = temp;
            curr = curr->next;
        }
        this->last = temp;
    }
    void del() {
        Node* curr = this->first;
        Node* temp = nullptr;
        while (curr != nullptr) {
            temp = curr->next;
            delete curr;
            curr = temp;
        }
        this->first = nullptr;
        this->last = nullptr;
    }

    public:
     LList() {
        this->first = nullptr;
        this->last = nullptr;
    }
    LList(const LList& other) {
        copy(other);
    }
    LList& operator=(const LList& other) {
        if (this != &other) {
            del();
            copy(other);
        }
        return *this;
    }
    ~LList() {
        del();
    }
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

    class Iterator {
        Node* curr;
        LList *list;
        public:
        Iterator(Node* curr, LList* list) {
            this->curr = curr;
            this->list = list;
        }
        Iterator& operator++() {
            if (curr == nullptr)
            {
                throw std::out_of_range("No more elements in list.");
            }
            curr=curr->next;
            return *this;
        }
        Iterator& operator--() {
            if (curr == nullptr)
            {
                if (list->first == nullptr)
                {
                    throw std::out_of_range("List is empty");
                } else
                {
                    curr = list->last;
                }
            } else
            {
                curr=curr->prev;
            }
            return *this;
        }
        int operator*() {
            return curr->data;
        }
        int operator!=(const Iterator& other) {
            return curr != other.curr;
        }
    };
    Iterator begin() {
        return Iterator(first, this);
    }
    Iterator end() {
        return Iterator(nullptr, this);
    }

};

int main() {
    LList l;
    l.insert_back(1);
    l.insert_back(2);
    LList l2(l);
    l2.insert_back(3);
    for (LList::Iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (LList::Iterator it2 = l2.begin(); it2 != l2.end(); ++it2) {
        std::cout << *it2 << std::endl;
    }
    l2 = l;
    for (LList::Iterator it2 = l2.begin(); it2 != l2.end(); ++it2) {
        std::cout << *it2 << std::endl;
    }
}