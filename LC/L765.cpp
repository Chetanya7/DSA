// TC: O(n^2)
// SC: O(1)

#include <vector>
#include <iostream>
using namespace std;

int minSwapCouples(vector<int> row){
    int n = row.size();
    int swaps = 0;

    for(int i=0; i<n; i=i+2){
        int person = row[i];
        int partner = person ^ 1; // find who is the partner of the person

        // find where the partner is seated
        int j=i+1;
        while(row[j]!=partner){
            j++;
        }

        if(j != (i+1)){
            row[j] = row[i+1];
            row[i+1] = partner;
            swaps++;
        }
    }

    return swaps;
}

int main(){
    vector<int> row = {3,2,0,1};
    int swaps = minSwapCouples(row);
    cout << swaps;
    return 0;
}