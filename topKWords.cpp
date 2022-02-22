//
// Created by OLX on 22/02/22.
//

#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool cmp(pair<int,string> p1,pair<int,string> p2 ) {

    if(p1.first==p2.first){
        return p1.second<p2.second;
    } else{
        return p1.first>p2.first;
    }

}
vector<string> topKFrequent(vector<string>& words, int k) {

    unordered_map<string , int> mp;
    vector<pair<int, string>> v;
    vector<string> ans;
    for(auto x: words) {
        mp[x]++;
    }
    for(auto x: mp) {
        v.emplace_back(x.second, x.first);
    }

    sort(v.begin(), v.end(), cmp);

    for(auto x:v){
        ans.push_back(x.second);
        if(ans.size()==k)break;
    }
    return ans;

}

int main() {
    vector<string> v =  {"ankush"};
    vector<string> a = topKFrequent(v, 2);
    return 0;
}