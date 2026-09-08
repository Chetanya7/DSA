// SC: O(1)

#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k){
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

// TC: O(n)
// SC: O(n)

// #include <vector>
// using namespace std;
// void rotate(vector<int>& nums, int k){
//     int n = nums.size();
//     vector<int> rotated(n);
//     for(int i=0; i<n; i++){
//         rotated[(i+k)%n] = nums[i];
//     }

//     for(int i=0; i<n; i++){
//         nums[i] = rotated[i];
//     }
// }