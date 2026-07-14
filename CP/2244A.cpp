#include <iostream>
#include <string>
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
        string s;
        cin >> s;

        //iterating through the string
        int count = 0;
        vector<int> lengths;
        for(int i=0; i<s.size(); i++) {
            if (s[i] == '#') count++;
            if (s[i] == '*' || i == s.size()-1) {
                lengths.push_back(count);
                count = 0;
            }
        }
        
        int max = -1;
        for(int i=0; i<lengths.size(); i++){
            if(lengths[i] > max){
                max = lengths[i];
            }
        }

        if(max%2 == 0){
            cout << max/2 << endl;
        } else {
            cout << (max/2)+1 << endl;
        }
    }
    return 0;
}