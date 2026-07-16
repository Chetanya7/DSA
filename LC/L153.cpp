/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int>& nums){
    int l = 0;
    int h = nums.size()-1;
    int ans = INT_MAX;

    while(l <= h){
        int mid = (l+h)/2;
        if(nums[l] <= nums[mid]) { //if the left half is the sorted half
            ans = min(ans, nums[l]);
            l = mid+1;
        } else {
            ans = min(ans, nums[mid]);
            h = mid-1;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {3,4,5,1,2};
    int min = findMin(nums);
    cout << min;
    return 0;
}