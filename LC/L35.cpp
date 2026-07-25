/*
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
*/

// Optimal: using binary search
// TC: O(logn)
// SC: O(1)

#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}