//
// Created by Ankush on 01/06/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
 * Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
    dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
    Output: 3
    sorted
    {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
    {9:10, 11:20, 11:30, 12:00 , 19:00, 20:00}
 */
struct Node {
    int arr,dep;
    Node(int arr, int dep) {
        this->arr=arr;
        this->dep=dep;
    }
};
struct comparator {
    bool operator() (Node &n1, Node & n2) {
        return n1.arr<n2.arr;
    }
};
priority_queue<Node, vector<Node>, comparator> pq; //fill it

// 2 pointer technique
int minPlatforms(vector<int> arrival, vector<int> dep, int n) {
    sort(arrival.begin(),arrival.end());
    sort(dep.begin(),dep.end());

    int i =1,j=0;
    int platform = 1;
    int res=1;

    while(i<n && j<n) {
        if (arrival[i]<=dep[j]) {
            platform++;
            i++;
        } else{
            platform--;
            j++;
        }
        res = max(res, platform);
    }
    return res;

}



