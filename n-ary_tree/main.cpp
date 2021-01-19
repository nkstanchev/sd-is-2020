#include <iostream>
#include <vector>

struct TreeNode {
    std::vector<std::pair<unsigned int, TreeNode*> > edges;
};

bool pathHelper(TreeNode *curr, unsigned int sum, unsigned int currSum) {
    bool res = false;
    int tempCurrSum = currSum;
    for(int i=0; i < curr->edges.size(); i++) {
        tempCurrSum += curr->edges[i].first;
        if (sum == tempCurrSum) {
            return true;
        }
        res = pathHelper(curr->edges[i].second, sum, tempCurrSum);
        if (res) {
            return true;
        }
        tempCurrSum = currSum;
    }
    return false;
}

bool path(TreeNode *root, unsigned int sum) {
    return pathHelper(root, sum, 0);
}

std::pair<int,int> biggestSumHelper(TreeNode *curr, size_t depth, int currSum) {
    int maxSum = currSum;
    int finalDepth = depth;
    for(int i=0; i < curr->edges.size(); i++) {
        std::pair<int,int> leafPair = biggestSumHelper(curr->edges[i].second, depth + 1, currSum+curr->edges[i].first);
        if (leafPair.first > maxSum) {
            maxSum = leafPair.first;
            finalDepth = leafPair.second;
        }
    }
    // listo
    return std::make_pair(maxSum, finalDepth);
}

size_t biggestSum(TreeNode *root) {
    std::pair<int,int> resPair = biggestSumHelper(root, 0, 0);
    return resPair.second;
}

int main() {
    TreeNode n1;
    TreeNode n2;
    TreeNode n3;
    TreeNode n4;
    TreeNode n5;
    TreeNode n6;
    TreeNode n7;
    n1.edges.push_back(std::make_pair(1, &n2));
    n1.edges.push_back(std::make_pair(9, &n3));
    n1.edges.push_back(std::make_pair(1, &n4));
    n2.edges.push_back(std::make_pair(2, &n5));
    n2.edges.push_back(std::make_pair(3, &n6));
    n4.edges.push_back(std::make_pair(4, &n7));
    // std::cout << path(&n1, 15) << std::endl;
    std::cout << biggestSum(&n1) << std::endl;
    return 0;
}