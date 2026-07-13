/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

// Bruteforce Approach
// TC: O(N^3)
// SC: O(?)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    int size = nums.size();
    for(int i = 0; i < size-2; i++) {
        for(int j = i+1; j < size-1; j++) {
            for(int k = j+1; k < size; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                } 
            }
        }
    }
    vector<vector<int>> triplets(st.begin(), st.end());
    return triplets;
}

void displayTriplets(vector<vector<int>>& triplets) {
    for(int i=0; i<triplets.size(); i++){
        for(int j=0; j<3; j++) {
            cout << triplets[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    vector<int> nums = {-1, 0,1,2,-1,-4};
    vector<vector<int>> triplets = threeSum(nums);
    displayTriplets(triplets);
    return 0;
}