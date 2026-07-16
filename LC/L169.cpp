/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
*/

//Bruteforce: TC: O(N2), SC: O(1)

/*#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int threshold = nums.size()/2;
    for(int i = 0; i < nums.size(); i++){
        int count = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == nums[i]) count++;
        }
        if(count > threshold) return nums[i];
    }
    return -1;
}*/

// Better
// TC: O(nlogn) as sort which uses Introsort (an hybrid of Heapsort, Quicksort and insertion sort) takes O(nlogn) time
// SC: O(logn) - Even thought the sorting is in-place, that is because Introsort is recursive and requires O(logn) auxiliary space on the stack.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>& nums){
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

int main() {
    vector<int> nums = {2,3,2,2,3,2};
    int ans = majorityElement(nums);
    cout << ans;
    return 0;
}