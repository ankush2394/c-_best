//
// Created by OLX on 02/06/21.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Given k sorted arrays of size n each, merge them and print the sorted output.

struct Node {
    int arrayIndex, startJ, value;
    Node(int i, int j, int val) {
        arrayIndex = i;
        startJ = j;
        value = val;
    }
};

struct comparator {
    bool operator() (Node &n1, Node &n2) {
        return n1.value>n2.value;
    }
};


void mergeKSortedArrays(vector<vector<int>> v) {

    priority_queue<Node,vector<Node>, comparator> pq;
    int k = v.size();
    int n = v[0].size();
    int j=0;
    for (int i=0;i<k;i++) {
        pq.push(Node(i,j,v[i][j]));
    }

    while (!pq.empty()) {
        Node n1 = pq.top();
        pq.pop();
        cout<<n1.value<<" ";
        if (n1.startJ<n-1) {
            pq.push(Node( n1.arrayIndex, n1.startJ + 1,v[n1.arrayIndex][n1.startJ + 1]));
        }
    }
}

//int main() {
//    vector<vector<int>> v{{2,11,19},{1,3,4},{1,2,3}};
//    mergeKSortedArrays(v);
//    return 0;
//}