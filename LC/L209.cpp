#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// value maximise karni hai aur length minimize

// int func(vector<int>& nums, int target){
//     int value = 0;
//     for(int num: nums){
//         value += num;
//     }

//     if(value < target) return 0; 

//     int l = 0;
//     int r = nums.size() - 1;

//     while(value >= target){
//         if(nums[l] < nums[r]){
//             value = value - nums[l];
//             if(value < target){
//                 return r-l+1;
//             }else{
//                 l++;
//             }
//         } else if(nums[r] < nums[l]){
//             value = value - nums[r];
//             if(value < target){
//                 return r-l+1;
//             } else{
//                 r--;
//             }
//         } else{
//             if(nums[l+1] < nums[r-1]){
//                 value = value - nums[l];
//                 if(value < target){
//                     return r-l+1;
//                 } else{
//                     l++;
//                 }
//             } else{
//                 value = value - nums[r];
//                 if (value < target){
//                     return r-l+1;
//                 } else{
//                     r--;
//                 }
//             }
//         }
//     }
// }

int func(vector<int>& nums, int target){
    int l = 0;
    int r = 0;
    int sum = nums[0];
    int length = INT_MAX;

    while (1)
    {
        if(sum >= target){
            length = min(r-l+1, length);
            sum = sum - nums[l];
            l++;
        } else{
            if(r != nums.size()-1){
                r++;
            } else{
                break;
            }
            sum = sum + nums[r];
        }

        if(l==nums.size()-1 && r == nums.size()-1){
            if(sum >= target){
                length = 1;
            }
            break;
        }
    }
    
    if(length != INT_MAX){
        return length;
    } else{
        return 0;
    }
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int result = func(nums, target);
    cout << result;
}