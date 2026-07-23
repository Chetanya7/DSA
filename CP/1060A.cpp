/*
Let's call a string a phone number if it has length 11 and fits the pattern "8xxxxxxxxxx", where each "x" is replaced by a digit.

For example, "80123456789" and "80000000000" are phone numbers, while "8012345678" and "79000000000" are not.

You have n cards with digits, and you want to use them to make as many phone numbers as possible. Each card must be used in at most one phone number, 
and you don't have to use all cards. The phone numbers do not necessarily have to be distinct.
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(char ch : s){
        if(ch == '8'){
            count++;
        }
    }

    int result = min(count, n/11);
    cout << result << endl;
    return 0;
}
