/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index
is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0
because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

// Better: using prefix sum
// TC: O(n)
// SC: O(n)

#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n+1,0);
    for(int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }

    for(int i=0; i<n; i++) {
        int lSum = prefix[i];
        int rSum = prefix[n] - lSum - nums[i];
        if(lSum == rSum) return i;
    }
    return -1;
}

// Optimal
// TC: O(n)
// SC: O(1)


// #include <iostream>
// #include <vector>
// using namespace std;

// int pivotIndex(vector<int>& nums) {
//     int sum = 0;
//     for(int num : nums) {
//         sum += num;
//     }
//     int lSum = 0;
//     int rSum = sum - nums[0];

//     for(int i=0; i<nums.size(); i++) {
//         if(lSum == rSum) return i;
//         if(i != nums.size()-1) {
//             lSum += nums[i];
//             rSum -= nums[i+1];
//         }

//     }
//     return -1;
// }