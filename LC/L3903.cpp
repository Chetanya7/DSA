#include <vector>
using namespace std;

// TC: O(n^2)
// SC: O(1)

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();

    for(int i=0; i<n; i++){
        int max = nums[i];
        for(int j=0; j<=i; j++){
            if(nums[j] > max){
                max = nums[j];
            }
        }

        int min = nums[i];
        for(int j=i; j<n; j++){
            if(nums[j] < min){
                min = nums[j];
            }
        }

        int instabilityScore = max - min;
        if(instabilityScore <= k){
            return i;
        }
    }

    return -1;
}