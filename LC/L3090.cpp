#include <string>
#include <unordered_map>
using namespace std;

// TC: O(n) where n = s.length() {due to amortization of the inner while loop operation to O(1) per iteration}
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

// ------------------------------------- OR -------------------------------------

// #include <string>
// using namespace std;

// // TC: O(n) where n = s.length() {due to amortization of the inner while loop operation to O(1) per iteration}
// // SC: O(1)

// int maximalLengthSubstring(string s) {
//     int left = 0;
//     int ans = 0;
//     int n = s.length();
//     int freq[26] = {};

//     for(int right=0; right<n; right++) {
//         freq[s[right] - 'a']++;

//         while(freq[s[right] - 'a'] > 2) {
//             freq[s[left] - 'a']--;
//             left++;
//         }

//         ans = max(ans, right - left + 1);
//     }

//     return ans;
// }