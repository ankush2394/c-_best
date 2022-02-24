//
// Created by Ankush on 23/02/22.
//

#include <vector>
using namespace std;


/// [1,1,9,8,5]

void findNextGreaterElem(int i, int n, vector<int> &A, int &ans, int num) {

    int l = i;
    int r = n;
    while (l<=r) {
        int m = l+(r-l)/2;
        if (A[m]>num) {
            ans = m;
            l=m+1;
        } else {
            r=m-1;
        }
    }
}

void continuousSwap(int start, int end, vector<int> &A) {
    while (start<end) {
        swap(A[start],A[end]);
        start++;
        end--;
    }
}

void nextPermutation(vector<int> &A) {
    if (A.size()<=1) {
        return ;
    }
    vector<int> ans;
    int n= A.size()-1;  /// last element
    int flag=1;
    for(int i=n-1;i>=0;i--) {
        if(A[i]>=A[i+1]) {
            flag*=1;
            continue;
        } else {
            int ans=-1;
            flag*=0;
            findNextGreaterElem(i+1,n,A, ans, A[i]);
            if(ans!=-1) {
                swap(A[i],A[ans]);
                continuousSwap(i+1,n,A);
            }
        }
    }

    if (flag) {
        /// implies cant do next permutation
        continuousSwap(0,n,A);
    }
    return;

}



int main() {

    return 0;
}