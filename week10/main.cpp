#include <iostream>
#include <stack>

struct Node {
    int data;
    Node *next;
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};
//1
void fillGaps(Node *root) {
    // обхождаме списъка
    Node *curr = root;
    while(curr->next != nullptr) {
        int val1 = curr->data;
        int val2 = curr->next->data;
        // if no need to insert
        if(val2 - val1 == 1) {
            curr = curr->next;
            continue;
        }
        // if we need to insert
        Node *origNext = curr->next;
        Node *tmp = new Node(val1+1, origNext);
        curr->next = tmp;

        curr = curr->next;
    }
    // проверяваме текущото със следващото
    // ако има нужда, вмъкваме нови елементи според условие
}
//2a
int matrix[4][4] = {
    {0, 0, 0, 0},
    {1,1,1,0},
    {0,1,1,1},
    {0,0,0,0}
};
struct Position {
    int r;
    int c;
    Position(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

bool downstairs(int sr, int sc, int tr, int tc) {
    if (matrix[sr][sc] == 1) return false;
    // while
    std::stack<Position*> st;
    if (matrix[sr][sc+1] == 0 && sc+1 < 4) {
        st.push(new Position(sr, sc+1));
    }
    if (matrix[sr+1][sc] == 0 && sr+1 < 4) {
        st.push(new Position(sr+1, sc));
    }
    while(!st.empty()) {
        Position *curr = st.top();
        st.pop();
        // if reached target exit
        if (curr->r == tr && curr->c == tc) {
            return true;
        }
        // else
        if (matrix[curr->r][curr->c+1] == 0 && curr->c+1 < 4) {
            st.push(new Position(curr->r, curr->c+1));
        }
        if (matrix[curr->r+1][curr->c] == 0 && curr->r+1 < 4) {
            st.push(new Position(curr->r+1, curr->c));
        }
    }
    return false;
}

//2b
std::string decode(std::string s) {
    std::stack<char> st;
    std::string res;
    for(int i = 0; i < s.length(); i++) {
        if (std::isdigit(s[i])) {
            st.push(s[i]);
            assert(s[i+1] == '[');
        }
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] == '[') {
            st.push(s[i]);
        }
        if (s[i] == ']') {
            while(!st.empty() && st.top() != '[') {
                res += st.top();
                st.pop();
            }
            // remove [ bracket
            st.pop();
            int cAsDigit = st.top() - '0';
            st.pop();
            for (int i = 0; i < cAsDigit; i++) {
                for (int j = res.length() - 1; j >= 0 ; j--) {
                    st.push(res[j]);
                }
            }
            res = "";
        }
    }
    
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    // Node* n1 = new Node(1, nullptr);
    // Node* n2 = new Node(3, nullptr);
    // Node* n3 = new Node(4, nullptr);
    // Node* n4 = new Node(8, nullptr);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // fillGaps(n1);
    
    //2a

    std::cout << downstairs(0,0,3,3) << std::endl;
    
    //2b
    // std::string s = "3[ac2[wfg]]";
    // std::cout << decode(s) << std::endl;
    return 0;
}