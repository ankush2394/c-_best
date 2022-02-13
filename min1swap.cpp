//
// Created by Ankush on 19/06/21.
//
#include <iostream>
#include <math.h>

using namespace std;

//min swaps required to group all 0s and 1s together
int minSwaps(int arr[], int n) {
    bool isOnePresent=false;
    for(int i=0;i<n;i++){
        if(arr[i]==1) {
            isOnePresent=true;
            break;
        }
    }
    if (!isOnePresent) {
        return -1;
    }

    //try for all one at left
    int i=0,j=n-1;
    int tempAns=0, tempAns1=0;
    while(i<j) {
        if (arr[j]==1) {
            if (arr[i]==0) {
                //swap(arr[i],arr[j]);
                tempAns++;
                i++;j--;
            } else {
                i++;
            }
        } else {
            j--;
        }
    }

    i=0;j=n-1;
    //try for all one at right
    while(i<j) {
        if (arr[i]==1) {
            if (arr[j]==0) {
                //swap(arr[i],arr[j]);
                tempAns1++;
                i++;j--;
            } else {
                j--;
            }
        } else {
            i++;
        }
    }
    cout<<tempAns<<tempAns1;
    return min(tempAns,tempAns1);

}
//TODO ************************* Always it has a very great approach find the subarray having largest 1s of size equal to total number of 1s in array and count 0s in it
//min swaps required to group all 1s together   -<slight diff in both>-
//it has a very great aproach
int minSwaps2(int arr[], int n) {
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) {
            cnt++;
        }
    }
    if (cnt==0) {
        return -1;
    }
    int windowSize=cnt;
    int zeroInWindow=0, oneInWindow=0;
    for(int i=0;i<windowSize;i++) {
        if(arr[i]==0) {
            zeroInWindow++;
        } else {
            oneInWindow++;
        }
    }
    int ans = INT_MIN, finalAns=0;
    if(oneInWindow>ans) {
        ans = oneInWindow;
        finalAns = zeroInWindow;
    }

    for(int i=windowSize;i<n;i++) {
        if(arr[i]==1) {
            oneInWindow++;
        } else {
            zeroInWindow++;
        }
        if (arr[i-windowSize]==0) {
            zeroInWindow--;
        } else {
            oneInWindow--;
        }

        if(oneInWindow>ans) {
            ans = oneInWindow;
            finalAns = zeroInWindow;
        }
    }
    return finalAns;

}

//int main() {
//    int arr[] = {1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1};
//    cout<<minSwaps2(arr,16);
//    return 0;
//}
