#include <iostream>
#include "bintree.h"


int main() {
    BinTree<int> myTree;
    myTree.add(1, "");
    myTree.add(2, "L");
    myTree.add(3, "R");
    myTree.add(4, "LL");
    myTree.add(5, "LR");
    myTree.add(6, "RL");
    // std::cout << myTree.sum() << std::endl;
    // std::cout << myTree.max() << std::endl;
    // std::cout << myTree.min() << std::endl;
    // myTree.printLeafs();
    // std::cout << myTree.sumLeafs() << std::endl;
    // myTree.dfs();
    // myTree.dfsIterative();
    myTree.bfs();
}