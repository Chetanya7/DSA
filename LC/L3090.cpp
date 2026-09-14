#include <string>
#include <unordered_map>
using namespace std;

// TC: O(n) where n = s.length()
// SC: O(k) where k is the number of distinct characters in the given string

int maximalLengthSubstring(string s) {
    unordered_map<char, int> freq;

    int left = 0;
    int ans = 0;

    for(int right=0; right<s.length(); right++) {
        freq[s[right]]++;

        while(freq[s[right]] > 2) {
            freq[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}