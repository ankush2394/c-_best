//
// Created by Ankush on 01/06/21.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int mergeIntervals(vector<pair<int,int>> v) {
    //sort them on staring time and store in stack and check o(n) memory ...
    sort(v.begin(),v.end());
    stack<pair<int,int>> s;

    if (s.empty()) {
        s.push(v[0]);
    }

    for(int i=1;i<v.size();i++){

        if (v[i].first<=s.top().second) {
            //overlapping it is
            s.top().second = max(v[i].second, s.top().second);
        } else {
            s.push(v[i]);
        }
    }

    //can easily be done in o(1) memory two , just sort and traverse and compare and push in ans
    //return whatever you want to
    return 0;
}

//int main() {
//
//    //MedianStream ms;
//    int arr[10] = {};
//    vector<pair<int, int>> v{{4,7},{3,4}};
//    cout<<mergeIntervals(v);
//    return 0;
//}
