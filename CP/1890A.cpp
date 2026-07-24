// TC: O(n)
// SC: O(1)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i=0; i<n; i++) {
            cin >> p[i];
        }

        int count = 0;
        unordered_map<int, int> mpp;
        for(int num : p){
            if(!(mpp.find(num) != mpp.end())){
                count++;
                if(count > 2){
                    cout << "No" << endl;
                    break;
                }
            }
            mpp[num]++;
        }

        if(count == 1){
            cout << "Yes" << endl;
        } else if(count == 2){
            int x = mpp.begin()->second; // the number of times the first number occurs in the array
            auto secondIt = next(mpp.begin());
            int y = secondIt->second;
            if(abs(x-y) == 1 || abs(x-y) == 0){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}