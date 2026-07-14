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
        int n;
        cin >> n;
        vector<long long> heights(n);
        for(int i=0; i<n; i++){
            cin >> heights[i];
        }

        long long prev=0;
        int ok=1;
        long long extra = 0;
        long long extra_new = 0;
        for(int i=0; i<n; i++){
            if((heights[i]+extra) <= prev){
                ok = 0;
                break;
            } else {
                extra_new = (heights[i]+extra)-prev-1;
                prev = (heights[i]+extra) - extra_new;
                extra = extra_new;
            }
        }

        if(ok){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}