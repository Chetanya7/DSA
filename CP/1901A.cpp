#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TC: O(xlogx)
// SC: O(n)

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        map<int, int> gs;
        int st;
        for(int i=0; i<n; i++){
            cin >> st;
            gs.insert({st,i});
        }

        int max = 0;
        int curr = 0;

        for(int i=1; i<=x; i++){
            curr++;
            if(gs.find(i) != gs.end()){ //if the node is a gas station
                if(max < curr){
                    max = curr;
                }
                curr = 0;
            }
        }

        for(int i=x-1; i>=0; i--){
            curr++;
            if(gs.find(i) != gs.end()){ //if the node is a gas station
                if(max < curr){
                    max = curr;
                }
                curr = 0;
            }
        }

        cout << max << endl;
    }
    
    return 0;
}