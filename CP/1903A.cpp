#include <iostream>
#include <vector>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i=0; i<n; i++) {
            cin >> nums[i];
        }

        // Check if the boxes are already sorted
        int sorted = 1;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                sorted = 0;
                break;
            }
        }

        if(sorted) {
            cout << "YES" << endl;
        } else if(k == 1){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}