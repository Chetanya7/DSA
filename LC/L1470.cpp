#include <vector>
using namespace std;

// TC: O(n)
// SC: O(1)

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2*n);

    int ptr1 = 0;
    int ptr2 = n;
    int i=0;

    while(ptr2 < 2*n) {
        if(i % 2 == 0) {
            ans[i++] = nums[ptr1++];
        } else {
            ans[i++] = nums[ptr2++];
        }
    }

    return ans;
}