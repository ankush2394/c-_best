//
// Created by Ankush on 13/06/21.
//
#include <iostream>
#include <cmath>
using namespace std;

// o(n) time o(1)
int maxProductSubarray(int arr[],int n) {

    int ansMax=arr[0];
    int ansMin=arr[0];
    int fAns=arr[0];
    for(int i=1;i<n;i++) {

        if (arr[i]<0) {
            swap(ansMax, ansMin);
        }
        ansMax = max(ansMax, arr[i]*ansMax);
        ansMin = min(ansMin, arr[i]*ansMin);

        fAns = max(fAns, ansMax);
    }
    return fAns;
}
//
//int main() {
//    return 0;
//}