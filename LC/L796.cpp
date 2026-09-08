#include <string>
using namespace std;

bool rotateString(string s, string goal){
    if(s.length() != goal.length()){
        return false;
    }

    string concatenated = s + s;
    if(concatenated.contains(goal)){
        return true;
    } else{
        return false;
    }
}