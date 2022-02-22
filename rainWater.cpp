#include <iostream>
#include <string>
#include <vector>
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

    /// O(n ) with O(n) memory

    int trap(vector<int>& height) {
        vector<pair<int, int>> store;
        int left_max = INT_MIN;
        int right_max = INT_MIN;
        for(int i=0;i<height.size();i++) {
            store[i].first = max(height[i], left_max);
            left_max = max(height[i], left_max);
        }

        for(int i=height.size()-1;i>=0;i--) {
            store[i].second = max(height[i], right_max);
            right_max = max(height[i], right_max);
        }

        int ans=0;
        for(int i=0;i<height.size();i++) {
            int dif = abs(min(store[i].first,store[i].second)-height[i]);
            ans += dif;
        }
        return ans;
    }
};