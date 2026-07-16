#include <iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n%3 == 0){
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
}