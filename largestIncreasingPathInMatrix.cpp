//
// Created by OLX on 03/07/21.
//

#include <iostream>
#include <vector>
using namespace std;

int dp1[201][201]={0};
int LIP(int i, int j, vector<vector<int>>& matrix, int prev)
{
    if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || prev>=matrix[i][j])
    {
        return 0;
    }
    if(dp1[i][j])
    {
        return dp1[i][j];
    }
    int a = 1+LIP(i+1,j,matrix,matrix[i][j]);
    int b = 1+LIP(i-1,j,matrix,matrix[i][j]);
    int c = 1+LIP(i,j+1,matrix,matrix[i][j]);
    int d = 1+LIP(i,j-1,matrix,matrix[i][j]);
    dp1[i][j]=max({a,b,c,d});
    return dp1[i][j];
}

//int longestIncreasingPath(vector<vector<int>>& matrix)
//{
//    int mx = 0;
//    for(int i=0;i<matrix.size();i++)
//    {
//        for(int j=0;j<matrix[0].size();j++)
//        {
//            mx=max(mx, LIP(i, j, matrix, INT_MIN));
//        }
//    }
//    return mx;
//}
