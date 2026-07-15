#include <iostream>
#include <string>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int max = 0;
        int curr = 0;
        int totalEC = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '.'){
                totalEC++;
                curr++;
            } else{
                if(max < curr){
                    max = curr;
                }
                curr = 0;
            }
            
            if(i == s.size()-1){
                if(max < curr){
                    max = curr;
                }
            }
        }

        if( max >= 3){
            cout << 2 << endl;
        } else if(max == 0){
            cout << 0 << endl;
        } else{
            cout << totalEC << endl;
        }

    }

    return 0;
}