//
// Created by OLX on 20/02/22.
//
#include <iostream>
#include <vector>

using namespace std;

//1800 -> 85
//row sorted n*m is odd
//time complexity = 32*r*log(c) , r rows c columns

int matrixMedian(vector<vector<int>> matrix) {

    int n = matrix.size();
    int m = matrix[0].size();
    int l=INT_MAX, r=INT_MIN;
    for(int i=0;i<n;i++) {
        l = min(l,matrix[i][0]);
        r = max(r, matrix[i][m-1]);
    }
    int desired = (n*m)/2+1;
    while (l<r) {
        int mid = l +(r-l)/2;
        int countElemsSmallerMid=0;
        for(int i=0;i<n;i++) {
            countElemsSmallerMid += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if(countElemsSmallerMid<desired) {
            l = mid+1;
        } else {
            r=mid;
        }
    }
    return l;

}

//int main() {
//    cout<<matrixMedian(vector<vector<int>> {{1,2,3},{4,5,6},{7,8,9}});
//    return 0;
//}

