/*
Maximum Distance Between FrogsThere are $N$ blocks numbered from 0 to N - 1, 
where the height of the ith block is given by blocks[i].
Two frogs initially start at the same block.
The first frog can only jump left to the adjacent block if that block has a height greater than or equal to the current block.
The second frog can only jump right to the adjacent block if that block has a height greater than or equal to the current block.
Both frogs jump as far as they can under these rules. 
The distance between the frogs is the number of blocks from the first frog's final position to the second frog's final position, 
inclusive (i.e., right_index - left_index + 1).
Return the maximum possible distance the two frogs can create between each other by choosing an optimal starting block.
*/

#include <vector>
using namespace std;

int maxDistance(vector<int>& heights){
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);

    left[0] = 0;
    for(int i=1; i<n; i++){
        if(heights[i-1] >= heights[i]){
            left[i] = left[i-1];
        } else{
            left[i] = i;
        }
    }

    right[n-1] = n-1;
    for(int i = n-2; i>=0; i--){
        if(heights[i+1] >= heights[i]){
            heights[i] = heights[i+1];
        } else{
            heights[i] = i;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, right[i]-left[i]+1);
    }

    return ans;
}