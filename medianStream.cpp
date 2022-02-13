//
// Created by Ankush on 31/05/21., median in a stream of integers
//


#include <iostream>
#include <string>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int,vector<int>, greater<int>> minHeap;

int getMedianFromStream(int X) {

    if (minHeap.empty()) {
        minHeap.push(X);
    } else {

        if (minHeap.top() < X) {
            minHeap.push(X);
        } else if (maxHeap.top() > X) {
            maxHeap.push(X);
        }
    }

    if (maxHeap.size()>minHeap.size()+1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }

    if (minHeap.size()>maxHeap.size()+1) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    if (minHeap.size() == maxHeap.size()) {
        return (minHeap.top()+maxHeap.top())/2;
    } else {
        if (maxHeap.size()>minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }
}

//int main() {
//
//    //MedianStream ms;
//    cout<<getMedianFromStream(1);
//    return 0;
//}



