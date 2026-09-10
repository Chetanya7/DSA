#include <vector>
using namespace std;

// TC: O(n)
// SC: O(n)

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> prefixMax(n);
    prefixMax[0] = nums[0];
    for(int i=1; i<n; i++) {
        if(nums[i] > prefixMax[i-1]) {
            prefixMax[i] = nums[i];
        } else {
            prefixMax[i] = prefixMax[i-1];
        }
    }

    vector<int> suffixMin(n);
    suffixMin[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--) {
        if(nums[i] < suffixMin[i+1]) {
            suffixMin[i] = nums[i];
        } else {
            suffixMin[i] = suffixMin[i+1];
        }
    }

    for(int i=0; i<n; i++){
        int instabilityScore = prefixMax[i] - suffixMin[i];
        if(instabilityScore <= k){
            return i;
        }
    }

    return -1;
}