#include <iostream>
#include <string>
using namespace std;


//rain water tapping o(1) memory
class RainWater{

public:
        int getWaterAmount() {

            //we always take left and right array to store the max of left and right to that point, for o(1) we will take two pointers and see

            int arr[10];
            int n, l = 1, r = n - 2;
            int maxLeft = arr[0];
            int maxRight = arr[n - 1];
            int trappedWater = 0;
            //because both extremes cant hold any water and start filling from lower extreme
            //2,3,0,0,8

            while (l <= r) {
                if (maxLeft < maxRight) {
                    if (arr[l] <= maxLeft) {
                        trappedWater += maxLeft - arr[l];
                    } else {
                        maxLeft = arr[l];
                    }
                    l++;
                } else {

                    if (arr[r] <= maxRight) {
                        trappedWater += maxRight - arr[r];
                    } else {
                        maxRight = arr[r];
                    }
                    r--;
                }
            }
        }
};