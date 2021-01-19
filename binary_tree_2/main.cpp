#include <iostream>
#include "bintree.h"
#include <fstream>

struct Node 
{
    int data; 
    Node *left, *right; 
    Node(int data, Node *left, Node *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
bool isSibling(Node *root, Node *a, Node *b) 
{
    if (root == nullptr)  return false; 
  
    return ((root->left==a && root->right==b)|| 
            (root->left==b && root->right==a)|| 
            isSibling(root->left, a, b)|| 
            isSibling(root->right, a, b)); 
} 
int level(Node *root, Node *curr, int lev) 
{  
    if (root == nullptr) return 0; 
    if (root == curr)  return lev; 
  
    int l = level(root->left, curr, lev+1); 
    if (l != 0)  return l; 
  
    return level(root->right, curr, lev+1); 
} 
bool isCousin(Node *root, Node *a, Node *b) 
{ 
    if ((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b))) {
        return true;
    }
    else return false;
} 

int main() {
    //BinTree<int> t;
    // t.add(4, "");
    // t.add(2, "L");
    // t.add(5, "R");
    // t.add(7, "LL");
    // t.add(2, "LR");
    // t.add(3, "RR");
    // std::cout << t.sumParentNodesWithChildX(2) << std::endl;
    // std::fstream my_file("file.txt");
    // my_file << "test" << std::endl;
    // my_file << t.sumParentNodesWithChildX(2) << std::endl;

    // char c; 
    // while(!my_file.eof()) {
    //     my_file >> c;
    //     std::string st(1, c);
    //     std::cout << "reading from file " << st << std::endl;
    // }
    //my_file.close();

    // std::cout << t.isFullBinaryTree();
    
    // Test insertOrdered works
    // t.insertOrdered(5);
    // t.insertOrdered(3);
    // t.insertOrdered(6);
    // t.insertOrdered(2);
    // t.insertOrdered(4);
    // t.insertOrdered(7);
    
    // Test isBST works
    // t.add(5, "");
    // t.add(3, "L");
    // t.add(6, "R");
    // t.add(2, "LL");
    // t.add(4, "LR");
    // t.add(7, "RR");
    // std::cout << t.isBST() << std::endl;


    // Are Mirror test
    // BinTree<int> t1;
    // t1.add(1, "");
    // t1.add(2, "R");
    // t1.add(3, "L");
    // t1.add(5, "RL");
    // t1.add(4, "RR");

    // BinTree<int> t2;
    // t2.add(1, "");
    // t2.add(2, "L");
    // t2.add(3, "R");
    // t2.add(5, "LR");
    // t2.add(4, "LL");

    // std::cout << t1.areMirror(t2) << std::endl;

    // Are cousins test
    // tree looks like
    //        1
    //      /   \
    //    2       3
    //     \     /
    //      4   5
    // Node n1(1, nullptr, nullptr);
    // Node n2(2, nullptr, nullptr);
    // Node n3(3, nullptr, nullptr);
    // Node n4(4, nullptr, nullptr);
    // Node n5(5, nullptr, nullptr);
    // n1.left = &n2;
    // n1.right = &n3;
    // n2.right = &n4;
    // n3.left = &n5;

    // std::cout << isCousin(&n1, &n4, &n5) << std::endl;
    // We use another node struct because we can't pass the exact nodes we want to check

    // Reads character by character
    // char c;
    // std::fstream myfile ("file.txt"); // also opens file
    // while (myfile >> c) {
    //     std::cout << c;
    // }
    // myfile.close();
    
    // Read string by string
    // reads whole line
    // std::string line;
    // std::fstream myfile ("file.txt"); // also opens file

    // while ( getline (myfile,line) )
    // {
    //     std::cout << line << '\n';
    // }
    // myfile.close();

    // Copy tree example
    // BinTree<int> t1;
    // t1.add(1, "");
    // t1.add(2, "R");
    // t1.add(3, "L");
    // t1.add(5, "RL");
    // t1.add(4, "RR");

    // BinTree<int> t2;
    // t2.copy(t1);

    return 0;
}

