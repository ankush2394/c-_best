//
// Created by OLX on 02/06/21.
//

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;


int cacheSize = 3;
list<int> dq; //doubly link list
unordered_map<int, bool> mp;   //check if the key already exists in cche or not
unordered_map<int, list<pair<int,int>>::iterator> mp1;
list<pair<int,int>> dq1;

void insert(int x) {
    //whenever you have to insert in the list , check if it already exists or not

    if (mp.find(x) != mp.end()) {
        //already in map cache
        int last = dq.back();
        dq.push_front(last);
        dq.pop_back();

    } else {
        //not in cache
        if (dq.size()<cacheSize) {
            dq.push_front(x);
        } else {
            int last = dq.back();
            dq.push_front(x);
            dq.pop_back();
            mp.erase(last);
        }
        mp[x]=true;
    }
}

int get(int key) {

    if(mp1.find(key)==mp1.end()) {
        return -1;
    }

    dq1.back();
    auto it = mp1[key];
    dq1.erase(it);
    dq1.push_back(make_pair(key, it->second));


    return mp[key];

}



//int main() {
//
//    //doubly linked list for easy removal and insertion from back and front in the form of list<int> dq;
//    //1 2 3 -> 3 2 1
//
//    insert(2);
//
//    return 0;
//}