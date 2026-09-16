#include <vector>
#include <unordered_set>
using namespace std;

// TC: O(n)
// SC: O(n)

int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int> s(nums.begin(), nums.end());

    int multiple = k;
    while(s.count(multiple)) {
        multiple += k;
    }

    return multiple;
}

// ------------------------------------- OR -------------------------------------

// #include <vector>
// #include <algorithm>
// using namespace std;

// // TC: O(n logn)
// // SC: O(1)

// int missingMultiple(vector<int>& nums, int k){
//     sort(nums.begin(), nums.end());
    
//     int multiple = k;
//     int n = nums.size();

//     for(int i=0; i<n; i++) {
//         if(nums[i] == multiple) {
//             multiple += k;
//         }
//     }

//     return multiple;
// }