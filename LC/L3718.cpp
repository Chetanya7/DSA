#include <vector>
#include <unordered_set>
using namespace std;

int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int> s(nums.begin(), nums.end());

    int multiple = k;
    while(s.count(multiple)) {
        multiple += k;
    }

    return multiple;
}