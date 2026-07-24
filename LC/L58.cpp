/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/

// TC: O(n)
// SC: O(1)

#include <iostream>
using namespace std;

int lenghtOfLastWord(string s){
    int n = s.length();
    int length = 0;
    int charScanned = 0;
    for(int i = n-1; i>=0; i--){
        if(charScanned){
            if(s[i] == ' ') return length;
        }
        if(s[i] != ' '){
            charScanned = 1;
            length++;
        }
    }
    return length;
}