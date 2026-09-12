#include <vector>
using namespace std;

// TC: O(n^2)
// SC: O(1)

bool uniformArray(vector<int>& nums1) {
    int n = nums1.size();

    bool even = true;
    
    for(int i=0; i<n; i++) {
        if(nums1[i] % 2 == 0) continue;


        int found = 0;
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            
            if((nums1[i] - nums1[j]) % 2 == 0) {
                found = 1;
                break;
            }
        }

        if(!found) {
            even = false;
            break;
        }
    }

    if(even) return true;

    bool odd = true;

    // trying to find an index where placing an odd number isn't possible
    for(int i=0; i<n; i++) {
        if((nums1[i] % 2) != 0) continue;

        int found = 0;
        for(int j=0; j<n; j++) {
            if(i == j) continue;

            if(((nums1[i] - nums1[j]) % 2) != 0) {
                found = 1;
                break;
            }
        }

        if(!found) {
            odd = false;
            break;
        }
    }

    if(odd) return true;

    return false;
}