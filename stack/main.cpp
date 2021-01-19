#include <iostream>
#include "list.h"
#include "stack.h"

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

// вариант с допълнителен брояч counter за всеки node
// bool isCyclic(Node* first) {
// 	Node* curr = first;
// 	while (curr != nullptr) {
// 		curr->counter++;
// 		if (curr->counter > 1) {
// 			return true;
// 		}

// 		curr = curr->next;
// 	}
// 	return false;
// }

// вариант с бавен и бърз пойнтър
bool isCyclic2(Node* first) {
	Node* curr = first;
	//Node* slow = first;
	Node* fast = first;
	while (curr != nullptr && fast->next != nullptr) {
		curr = curr->next;
		fast = fast->next->next;
		if (curr == fast) return true;
	}
	return false;
}

void reverseList(Node* first) {
	Node* prev = nullptr;
	Node* curr = first;
	Node* next = nullptr;
	while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
	}
}

bool isValidExpr(std::string s) {
	Stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		// ignore other chars
		if (s[i] == '(' || s[i] == ')') {
			if (s[i] == '(') {
				st.add('(');
			}
			else if (s[i] == ')') {
				try {
                    st.remove();
                } catch (const std::underflow_error& e) {
                    return false;
                }
			}
		}
	}
	return st.empty();
}

int main() {
    // Test LList and Stack
    // LList<int> l;
    // l.insert_back(1);
    // l.insert_back(2);
    // LList<int> l2(l);
    // l2.insert_back(3);
    // for (LList<int>::Iterator it = l.begin(); it != l.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }
    // for (LList<int>::Iterator it2 = l2.begin(); it2 != l2.end(); ++it2) {
    //     std::cout << *it2 << std::endl;
    // }
    // l2 = l;
    // for (LList<int>::Iterator it2 = l2.begin(); it2 != l2.end(); ++it2) {
    //     std::cout << *it2 << std::endl;
    // }
    // Stack<char> st;
    // st.add('a');
    // Problems

    // IsCyclic 1 and 2
    Node n1(1, nullptr, nullptr);
	Node n2(2, nullptr, nullptr);
	Node n3(3, nullptr, nullptr);
	Node n4(4, nullptr, nullptr);
	Node n5(5, nullptr, nullptr);
	n1.next = &n2;
	n2.prev = &n1;
	n2.next = &n3;
	n3.prev = &n2;
	n3.next = &n4;
	n4.prev = &n3;
	n4.next = &n5;
	n5.prev = &n4;
	//n5.next = &n2;
	//std::cout << isCyclic2(&n1) << std::endl;
	// reverseList(&n1);
	std::cout << isValidExpr("(..(.)..))") << std::endl;
    std::cout << isValidExpr("(..(.)..)") << std::endl;
}