#include <iostream>
#include <vector>
using namespace std;

class MapNode {

public:
    string key;
    int value;
    MapNode *next;
    MapNode() {
        this->key = key;
        this->value = value;
        this->next =  NULL;
    }

};

class HashMap {

public:
    int loadFactor = 7;  //70%
    long long m = 1e9+7;
    int bucketSize = 11;
    int mapSize=0;
    vector<MapNode*> buckets;
    HashMap() {
        for(int i=0;i<bucketSize;i++){
            buckets.push_back(NULL);
        }
    }

    void insert(string key, int val) {
        MapNode *node = new MapNode;
        node->key = key;
        node->value = val;
        node->next = NULL;
        int pos = getHash(key);
        insertIntoBuckets(node, pos);
    }

    int getHash(string key) {

        long long sum = 0;
        for(int i = 0;i<key.length();i++) {
            sum  += (int)(key[i])*i*m;
        }
        return (int)(sum%bucketSize);
    }

    void insertIntoBuckets(MapNode * node, int pos) {
        MapNode *head = buckets[pos];
        MapNode * temp = head;
        int cnt=0;
        while(temp && temp->next != NULL) {
            if (temp->value == node->value) {
                return;
            }
            temp = temp->next;
            cnt++;
        }

        if(!temp) {
            buckets[pos] = node;  //first insertion
        } else {
            temp->next = node;
        }

        if (cnt>loadFactor) {
            //do Rehashing , increment bucket size by big prime, copy old vector  into newer vector
            bucketSize = nextBigPrime(bucketSize);
            reHash();
        }
        mapSize++;
    }


    int nextBigPrime(int currPrime) {
        int potentialAns = currPrime*2+1;
        int i=1;
        int cnt=0;
        while(potentialAns<m) {
            i=1;cnt=0;
            while (i * i <= potentialAns) {
                if (potentialAns % i == 0) {
                    cnt++;
                }
                i++;
            }
            if (cnt < 2) {
                return potentialAns;
            }
            potentialAns++;
        }
        return 0;
    }


    void reHash() {
        vector<MapNode*> oldBuckets = buckets;
        buckets  = vector<MapNode*>(bucketSize);
        mapSize = 0;

        vector<MapNode*> v1(bucketSize);
        for(int i=0;i<oldBuckets.size();i++) {
            if(oldBuckets[i]) {
                MapNode * head = oldBuckets[i];
                MapNode * temp = head;
                while (temp != NULL) {
                    insert(temp->key, temp->value);
                }
            }
        }
    }

    int getMapSize() {
        return mapSize;
    }

    int getKValueFromMap(string key) {
        int pos = getHash(key);
        MapNode *head = buckets[pos];
        MapNode * temp = head;

        if(head == NULL) {
            return -1;
        } else{
            while(temp!=NULL) {
                if (temp->key == key) {
                    return temp->value;
                }
                temp=temp->next;
            }
        }
        return -1;
    }

};

//int main() {
//
//   HashMap hashMap;
//   hashMap.insert("123",123);
//   cout<<hashMap.getMapSize();
//   cout<<hashMap.getKValueFromMap("123");
//
//    return 0;
//}
