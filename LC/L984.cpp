#include <string>
using namespace std;

string strWithout3a3b(int a, int b){
    string s;

    while(a > 0 || b > 0){
        bool canUseA = (a > 0 && !(s.size() >= 2 && s[s.size()-1] == 'a' && s[s.size()-2] == 'a'));
        bool canUseB = (b > 0 && !(s.size() >= 2 && s[s.size()-1] == 'b' && s[s.size()-2] == 'b'));

        if(canUseA && canUseB){
            if(a >= b){
                s += 'a';
                a--;
            } else{
                s += 'b';
                b--;
            }
        } else if (canUseA){
            s += 'a';
            a--;
        } else {
            s += 'b';
            b--;
        }
    }

    return s;
}