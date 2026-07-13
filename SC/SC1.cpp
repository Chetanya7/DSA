// Given a vector of integers nums, remove all the duplicates from it.

#include <iostream>
#include <vector>
using namespace std;

// Bruteforce
// TC: O(N^2)
// SC: O(N)

vector<int> removeDuplicates(vector<int>& nums) {
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

void display(vector<int>& result) {
    for(int i : result) {
        cout << i << "\t";
    }
}

int main() {
    vector<int> nums = {1,2,3,2,4,1};
    vector<int> result = removeDuplicates(nums);
    display(result);

    return 0;
}