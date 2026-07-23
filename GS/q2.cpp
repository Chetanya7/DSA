/*
Count triplets (i<j<k) in an array such that arr[i]>arr[j]>arr[k] 
*/

// Better
// TC: O(n^2)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int>& nums) {
    int n = nums.size();
    int triplets = 0;
    for(int j=1; j<n-1; j++) {
        int greaterLeft = 0;
        int smallerRight = 0;
        for(int i=0; i<n; i++) {
            if((i<j) && (nums[j]<nums[i])){
                greaterLeft++;
            }
            if((i>j) && (nums[j] > nums[i])){
                smallerRight++;
            }
        }
        triplets += greaterLeft*smallerRight;
    }
    return triplets;
}

int main(){
    vector<int> nums = {5,3,4,2,1};
    int count = countTriplets(nums);
    cout << count;
}