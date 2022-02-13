#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int arr[5] = {2,3,7,8,10};
const int sum =15, n = 5;
int coin[3] = {3,12,5};
int sum1 = 2;
//int dp[n+1][sum+1];
int dp[7][8];
vector<vector<int>> ans;


//subset exists with given sum
bool exists(int arr[], int n, int sum) {
    if(sum==0) {
        return true;
    }
    if (n<=0) {
        return false;
    }

    if (dp[n][sum]!=-1) {
        return dp[n][sum];
    }

    if (arr[n-1]<=sum) {
        return dp[n][sum] = exists(arr,n-1,sum-arr[n-1] ) || exists(arr, n-1,sum);
    } else {
        return dp[n][sum] = exists(arr, n-1,sum);
    }
}


//subset exists with given sum then give the subset/all subsets/shortest subset/etc
bool subsetWithGivenSum(int arr[], int n, int sum, vector<int> v) {
    if(sum==0) {
        ans.push_back(v);
        return true;
    }
    if (n<=0) {
        return false;
    }

    if (dp[n][sum]!=-1) {
        return dp[n][sum];
    }

    if (arr[n-1]<=sum) {
        v.push_back(arr[n-1]);
        bool ans1 = subsetWithGivenSum(arr,n-1,sum-arr[n-1], v);
        if (!v.empty()){v.pop_back();}
        bool ans2 = subsetWithGivenSum(arr, n-1,sum, v);
        return dp[n][sum] = ans1 || ans2;
    } else {
        return dp[n][sum] = subsetWithGivenSum(arr, n-1,sum, v);
    }
}


int minCoins(int coins[], int n, int sum) {
    if (n == 0) {
        return INT_MAX - 1;
    }
    if (sum == 0) {
        return 0;
    }

    if (coins[n - 1] <= sum) {
        return min(1 + minCoins(coins, n, sum - coins[n - 1]), minCoins(coins, n - 1, sum));
    } else {
        return minCoins(coins, n - 1, sum);
    }
}

void minCount(int n, int count, int &result) {
    //add 1 to number, subtract 1 from number and if its even yoy can divide that number by two , each operation require one step
    //count min steps to reach a number to one
    if (count > result) {
        return ;
    }
    if(n<=1){
        if (count<result) {
            result = count;
        }
        return;
    }

    minCount(n-1,count+1,result);
    minCount(n+1,count+1,result);

    if (n%2==0){
        minCount(n/2,count+1,result);
    }
}


int lcs(string str1, string str2, int n, int m, string &ans, string s1) {
    if (n==0 || m==0 ) {
        if (s1.length()>ans.length()) {
            ans = s1;
        }
        return 0;
    }

    if (str1[n-1] == str2[m-1]) {
        s1 = s1+str1[n-1];
        return 1+lcs(str1, str2, n-1,m-1, ans, s1);
    } else {
        return max(lcs(str1, str2, n,m-1, ans,s1), lcs(str1, str2, n-1,m, ans,s1));
    }

}
//memoised
int lcsMemoised(string str1, string str2, int n, int m, string &ans, string s1) {
    if (n==0 || m==0 ) {
        if (s1.length()>ans.length()) {
            ans = s1;
        }
        return 0;
    }

    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    if (str1[n-1] == str2[m-1]) {
        s1 = s1+str1[n-1];
        return dp[n][m]= 1+lcs(str1, str2, n-1,m-1, ans, s1);
    } else {
        return dp[n][m] = max(lcs(str1, str2, n,m-1, ans,s1), lcs(str1, str2, n-1,m, ans,s1));
    }

}

void lcSubstring(string str1, string str2, int n, int m, int &ans1, int &res) {
    if (n==0 || m==0 ) {
        return ;
    }
    if (str1[n-1] == str2[m-1]) {
        ans1++;
        if (ans1>res) {
            res=ans1;
        }
        return lcSubstring(str1, str2, n-1,m-1,ans1, res);
    } else {
        ans1=0;
        return lcSubstring(str1, str2, n-1,m-1,ans1, res);
    }
}


//int main() {
//
//    memset(dp,-1,sizeof(dp));
//    vector<int> v;
//    int result=INT_MIN;
//
//    string ans;
//    int ans1 = 0;
//
//    //cout<<lcsMemoised("AGGTAB","GXTXAYB", 6,7,ans, "")<<" "<<ans;
//    lcSubstring("abcde","abfce", 5,5, ans1, result);
//    cout<<" "<<result;
//
//
//    return 0;
//
//
//}
