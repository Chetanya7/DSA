/*
Given an integer array nums and an integer k, 
return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
*/

// Bruteforce
// TC: O(n^2)
// SC: O(1)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int kDiff(vector<int>& nums, int k) {
    int count = 0;
    for(int i=0; i<nums.size()-1; i++) {
        for(int j=i+1; j<nums.size(); j++) {
            int diff = nums[i] - nums[j];
            if (abs(diff) == k){
                count ++;
            }
        }
    }
    return count;
}
