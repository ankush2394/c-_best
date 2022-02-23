//
// Created by OLX on 02/06/21.
//

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;


int cacheSize = 3;
unordered_map<int, list<pair<int,int>>::iterator> mp1;
list<pair<int,int>> dq1;

void insert(int key, int value) {
    //whenever you have to insert in the list , check if it already exists or not

    if (mp1.find(key) != mp1.end()) {
        //it exists in cache
        auto it = mp1[key];
        dq1.erase(it);
        dq1.push_front(make_pair(key, value));
        mp1[key] = dq1.begin();
    } else {
        //doesnt exist in cache
        dq1.push_front(make_pair(key, value));
        mp1[key]=dq1.begin();

        if(dq1.size()>cacheSize) {
            mp1.erase(mp1.find(dq1.back().first));
            dq1.pop_back();
        }
    }
}

int get(int key) {

    if(mp1.find(key)==mp1.end()) {
        return -1;
    }


    auto it = mp1[key];
    int val = it->second;
    dq1.erase(it);
    dq1.push_front(make_pair(key, val));
    mp1[key] = dq1.begin();
    return val;

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