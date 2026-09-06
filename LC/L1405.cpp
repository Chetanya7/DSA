#include <string>
using namespace std;

string longestDiverseString(int a, int b, int c){
    string s;

    while(a > 0 || b > 0 || c > 0){
        bool canUseA = a > 0 && !(s.size() >= 2 && s[s.size()-1] == 'a' && s[s.size()-2] == 'a');
        bool canUseB = b > 0 && !(s.size() >= 2 && s[s.size()-1] == 'b' && s[s.size()-2] == 'b');
        bool canUseC = c > 0 && !(s.size() >= 2 && s[s.size()-1] == 'c' && s[s.size()-2] == 'c');

        if(canUseA && canUseB && canUseC){
            if(a >= b && a >=c){
                s += 'a';
                a--;
            } else if( b >= a && b >= c){
                s += 'b';
                b--;
            } else{
                s += 'c';
                c--;
            }
        } else if(canUseA && canUseB){
            if(a >= b){
                s += 'a';
                a--;
            } else{
                s += 'b';
                b--;
            }
        } else if(canUseA && canUseC){
            if(a >= c){
                s += 'a';
                a--;
            } else{
                s += 'c';
                c--;
            }
        } else if(canUseB && canUseC){
            if(b >= c){
                s += 'b';
                b--;
            } else{
                s += 'c';
                c--;
            }
        } else if(canUseA){
            s += 'a';
            a--;
        } else if(canUseB){
            s += 'b';
            b--;
        } else if(canUseC){
            s += 'c';
            c--;
        } else{
            return s;
        }
    }

    return s;
}