/*Given an array of integers "nums" and an integer "target", return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/

// Bruteforce: TC - O(N2), SC: O(1)
/* #include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(nums[i] + nums[j] == target) {
                return {i,j};
            }
        }
    }
    return {};
}

void display(vector<int>& indices) {
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << "\t";
    }
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int target = 6;
    vector<int> indices = twoSum(nums, target);
    display(indices);
    return 0;
}*/

// Better
// TC: O(nlogn)
// SC: O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    map<int,int> m;
    for(int i=0; i<nums.size(); i++){
        int diff = target - nums[i];
        if(m.find(diff) != m.end()) {
            return {m[diff], i};
        }
        m.insert({nums[i],i});
    }
    return {};
}