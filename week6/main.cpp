#include <iostream>
#include <string>
#include <stack>

void naiveNextGreaterElement(int arr[4], int length) {
    bool hasGreater = false;
    for(int i=0; i < length; i++) {
        std::cout << arr[i] << " ";
        for(int j=i+1; j < length; j++) {
            if (arr[i] < arr[j]) {
                std::cout << arr[j] << std::endl;
                hasGreater = true;
                break;
            }
        }
        if (!hasGreater) {
            std::cout << -1 << std::endl;
        }
        hasGreater = false;
    }
}

bool isOperator(char o) {
    switch(o) {
        case '+':
        case '-':
        case '*':
        case '/':
        return true;
        default:
        return false;
    }
}
void prefixToPostfix() {
    std::string expr = "*+abc"; // cab+*
    // std::stack<char> operators;
    std::stack<std::string> letters;
    std::string res;
    std::string temp;
    for (int i=expr.length(); i >= 0; i--) {
        if (expr[i] >= 'a' && expr[i] <= 'z') {
            std::string s; s.push_back(expr[i]);
            letters.push(s);
        }
        if (isOperator(expr[i])) {
            // op a b
            // a b op
            temp = letters.top();
            letters.pop();
            temp += letters.top() + expr[i];
            letters.pop();
            letters.push(temp);
        }
    }
    while(!letters.empty()) {
        res += letters.top();
        letters.pop();
    }
    std::cout << res << std::endl;
}

void postfixToPrefix() {
    std::string expr = "ab+c*"; // *+abc
    std::stack<std::string> letters;
    std::string res;
    std::string temp;

    for (int i=0; i < expr.length(); i++) {
        if (expr[i] >= 'a' && expr[i] <= 'z') {
            std::string s; s.push_back(expr[i]);
            letters.push(s);
        }
        if (isOperator(expr[i])) {
            std::string first =  letters.top();
            letters.pop();
            std::string second = letters.top();
            letters.pop();
            temp = expr[i] +  second + first;
            letters.push(temp);
        }
    }
    while(!letters.empty()) {
        res += letters.top();
        letters.pop();
    }
    std::cout << res << std::endl;
}

void NextGreaterElement(int arr[4], int length) {
    std::stack<int> st;
    st.push(arr[0]);
    for(int i=1; i < 4; i++) {
        while(!st.empty() && st.top() < arr[i]) {
            std::cout << st.top() << " " << arr[i] << std::endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()) {
        std::cout << st.top() << " " << -1 << std::endl;
            st.pop();
    }
}

int main() {
    int arr[4] = {13, 7, 6, 12};
    naiveNextGreaterElement(arr, 4);
    NextGreaterElement(arr, 4);
    prefixToPostfix();
    postfixToPrefix();
}