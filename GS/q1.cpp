/*
Rearrange an unsorted array so elements alternate: largest, smallest, 2nd-largest, 2nd-smallest, and so on.
*/
// TC: O(nlogn) [due to introsort]
// SC: O(n) [due to the result array]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> meanderingArray(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<int> result;
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        result.push_back(nums[r]);
        if(r != l){
            result.push_back(nums[l]);
        }
        r--;
        l++;
    }
    return result;
}

int main() {
    vector<int> nums = {2,6,3,9,8,0,4,1};
    vector<int> result = meanderingArray(nums);
    for(int i=0; i<nums.size(); i++) {
        cout << result[i] << "  ";
    }
    return 0;
}