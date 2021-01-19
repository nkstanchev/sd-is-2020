#include <iostream>
#include <unordered_set>
#include <unordered_map>

void printDistinctElementsSet() {
    int arr[5] = {3,5,7,3,5};
    std::unordered_set<int> s;
    for(int i=0; i < 5; i++) {
        s.insert(arr[i]);
    }
     /*
    3
    5
    7
    order is not guaranteed
    */
    for(auto it = s.begin(); it != s.end(); it++) {
        std::cout << *it << std::endl;
    }
}

void printDistinctElementsMap() {
    int arr[5] = {3,5,7,3,5};
    std::unordered_map<int, int> m;
    for(int i=0; i < 5; i++) {
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]]++;
        } else {
            m[arr[i]] = 1;
        }
    }
    /*
    3 -> 2
    5 -> 2
    7 -> 1
    order is not guaranteed
    */
    for(auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << std::endl;
    }
}

void printAllDuplicates() {
    int arr[5] = {3,5,7,3,5};
    std::unordered_map<int, int> m;
    for(int i=0; i < 5; i++) {
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]]++;
        } else {
            m[arr[i]] = 1;
        }
    }
    /*
    3 -> 2
    5 -> 2
    7 -> 1
    order is not guaranteed
    */
    for(auto it = m.begin(); it != m.end(); it++) {
        if (it->second > 1) {
            std::cout << it->first << std::endl;
        }
    }
}

void printAllNonRepeating() {
    int arr[5] = {3,5,7,3,5};
    std::unordered_map<int, int> m;
    for(int i=0; i < 5; i++) {
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]]++;
        } else {
            m[arr[i]] = 1;
        }
    }
    /*
    3 -> 2
    5 -> 2
    7 -> 1
    order is not guaranteed
    */
    for(auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) {
            std::cout << it->first << std::endl;
        }
    }
}

void printMostFreq() {
    int arr[16] = {3,5,7,3,5,6,7,9,12,15,33,25,6,3,1,6};
    std::unordered_map<int, int> m;
    for(int i=0; i < 16; i++) {
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]]++;
        } else {
            m[arr[i]] = 1;
        }
    }
    /*
    3 -> 3
    5 -> 2
    7 -> 2
    6 -> 3
    9 -> 1
    12 -> 1
    1 -> 1
    33 -> 1
    25 -> 1
    order is not guaranteed
    */
   int maxOccur = INT_MIN;
   int maxOccurNum = -1;
   for(auto it = m.begin(); it != m.end(); it++) {
        if (it->second > maxOccur) {
            maxOccur = it->second;
            maxOccurNum = it->first;
        }
    }
    std::cout << maxOccurNum << std::endl;
}

bool checkIfArrEq() {
    int arr[4] = {1, 2, 2, 3};
    int arr2[4] = {2, 1, 3, 2};
    std::unordered_map<int, int> m;
    for(int i=0; i < 4; i++) {
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]]++;
        } else {
            m[arr[i]] = 1;
        }
    }
    std::unordered_map<int, int> m2;
    for(int i=0; i < 4; i++) {
        if (m2.find(arr2[i]) != m2.end()) {
            m2[arr2[i]]++;
        } else {
            m2[arr2[i]] = 1;
        }
    }
    /*
    m1
    1 -> 1
    2 -> 2
    3 -> 1
    m2
    1 -> 1
    2 -> 2
    3->1
    order is not guaranteed
    */

   /*
    m1 // O(n)
    m2 // O(n)
    for pair : m1
        exists m2[pair->first] // O(1)
        m2[pair->first] // O(1) == pair->second
   */
    for(auto it = m.begin(); it != m.end(); it++) {
        if (m2.find(it->first) == m2.end()) {
            return false;
        }
        if (m2[it->first] != it->second) {
            return false;
        }
    }
    return true;
}

int main() {
    //printDistinctElementsSet();
    //printDistinctElementsMap();
    //printAllDuplicates();
    //printAllNonRepeating();
    //printMostFreq();

    std::cout << checkIfArrEq() << std::endl;
    return 0;
}