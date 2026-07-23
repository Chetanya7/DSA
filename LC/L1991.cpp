/*
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.
*/

// Optimal
// TC: O(n)
// SC: O(1)

#include <vector>
using namespace std;

int middleIndex(vector<int>& nums) {
    int sum = 0;
        for(int num : nums){
            sum += num;
        }

        int lSum = 0;
        for(int i=0; i<nums.size(); i++){
            int rSum = sum - lSum - nums[i];
            if(lSum == rSum) return i;
            lSum += nums[i];
        }
        return -1;
}