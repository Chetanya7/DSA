#include <vector>
using namespace std;

// TC: O(450)
// SC: O(20)

int totalNumbers(vector<int>& digits) {
    int ans = 0;

    vector<int> freq(10, 0);
    for(int digit : digits){
        freq[digit]++;
    }


    for(int i=100; i<999; i+=2){
        // int hundreds = i/100;
        // int tens = (i - hundreds * 100) / 10;
        // int units = i - hundreds * 100 - tens * 10;

        int units = i % 10;
        int tens = (i/10) % 10;
        int hundreds = i / 100;

        vector<int> req(10, 0);
        req[hundreds]++;
        req[tens]++;
        req[units]++;

        bool hundredsValid = req[hundreds] <= freq[hundreds];
        bool tensValid = req[tens] <= freq[tens];
        bool unitsValid = req[units] <= freq[units];

        if(hundredsValid && tensValid && unitsValid){
            ans++;
        }
    }

    return ans;
}