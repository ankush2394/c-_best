//
// Created by OLX on 23/02/22.
//


#include <iostream>
#include <vector>

using namespace std;

void largerTwoElemsArray(vector<int> v) {

    int first =INT_MIN, second = INT_MIN;

    for(int i=0;i<v.size();i++) {

        if(v[i]>first) {
            second = first;
            first = v[i];
        } else if (v[i]>second) {
            second = v[i];
        }
    }

    cout<<first<<" "<<second<<endl;
    return;

}

void largerThreeElemsArray(vector<int> v) {

    int first =INT_MIN, second = INT_MIN, third = INT_MIN;

    for(int i=0;i<v.size();i++) {

        if(v[i]>first) {
            third = second;
            second = first;
            first = v[i];
        } else if (v[i]>second) {
            third = second;
            second = v[i];
        } else if (v[i]>third) {
            third = v[i];
        }
    }

    cout<<first<<" "<<second<<" "<<third;
    return;

}
int main() {

    largerTwoElemsArray(vector<int> {1,2,3,4,4});
    largerThreeElemsArray(vector<int> {1,2,1,3,4,9});

    return 0;
}