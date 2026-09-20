#include <string>
#include <vector>
using namespace std;

// This program is for a generalized version of the problem. 
// The generalization assumes that the string can be non-binary, 
// and the character that is to have k occurences is also provided by the user.

// TC: O(n*n)
// SC: O(n) where n = s.length() as 'occurences'can at max contain all the indices of the string s

string shortestBeautifulSubstring(string s, int k, char ch) {
    int n = s.length();
    vector<int> occurences; // an array to store the indices on which ch occurs

    // traversing through the string and constructing the 'occurences' array
    for(int i=0; i<n; i++) {
        if(s[i] == ch) {
            occurences.push_back(i);
        }
    }

    int len = n+1; // len will store the length of the shortest beautiful substring.
    // It's value is initialized to n+1 as we know that the maximum length of the beautiful substring can be n.

    int left_index; // stores the starting index of the beautiful substring
    int right_index; // stores the last index of the beautiful substring
    int left = 0; // points to the position in the 'occurences' array that contains the starting index of the b.s
    int right = left + k -1; // points to the position in the 'occurences' array that contains the last index of the b.s

    while(right < occurences.size()) {
        int width = occurences[right] - occurences[left] + 1; // calculating the length of the beautiful substring
        if(width < len) {
            len = width;
            left_index = occurences[left];
            right_index = occurences[right];
        }

        if(width == len) {
            // Implementing the lexicographic tie breaker
            for(int i=0; i<len; i++) {
                if(s[occurences[left]+i] < s[left_index+i]) {
                    left_index = occurences[left];
                    right_index = occurences[right];
                    break;
                }

                if(s[occurences[left]+i] > s[left_index+i]) {
                    break;
                }
            }
        }

        left++;
        right++;
    }

    if(len == n+1) {
        return ""; // Returning an empty string if no beautiful substring is found
    } else {
        string ans = "";
        for(int i=left_index; i<=right_index; i++) {
            ans += s[i];
        }

        return ans;
    }
}