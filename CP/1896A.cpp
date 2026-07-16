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
        vector<int> p(n+1);
        for(int i=1; i<=n; i++) {
            cin >> p[i];
        }

        if(p[1] == 1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}