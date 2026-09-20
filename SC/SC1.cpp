// Given a vector of integers nums, remove all the duplicates from it.

#include <iostream>
#include <vector>
using namespace std;

// Bruteforce
// TC: O(N^2)
// SC: O(1)

vector<int> removeDuplicates1(vector<int>& nums) {
    vector<int> result;
    int size = nums.size();

    for(int i=0; i<size; i++) {
        int found = 0;
        for(int j=0; j<result.size(); j++) {
            if(nums[i] == result[j]) {
                found = 1;
                break;
            }
        }
        if(!found){
            result.push_back(nums[i]);
        }
    }
    return result;
}

// Optimal
// TC: O(n)
// SC: O(n)

#include <unordered_set>

vector<int> removeDuplicates2(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    unordered_set<int> s;

    for(int i=0; i<n; i++) {
        if(!s.count(nums[i])) {
            s.insert(nums[i]);
            result.push_back(nums[i]);
        }
    }

    return result;
}


void display(vector<int>& result) {
    for(int i : result) {
        cout << i << "\t";
    }
}

int main() {
    vector<int> nums = {1,2,3,2,4,1};
    vector<int> result = removeDuplicates2(nums);
    display(result);

    return 0;
}