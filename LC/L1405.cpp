// #include <string>
// using namespace std;

// string longestDiverseString(int a, int b, int c){
//     string s;

//     while(a > 0 || b > 0 || c > 0){
//         bool canUseA = a > 0 && !(s.size() >= 2 && s[s.size()-1] == 'a' && s[s.size()-2] == 'a');
//         bool canUseB = b > 0 && !(s.size() >= 2 && s[s.size()-1] == 'b' && s[s.size()-2] == 'b');
//         bool canUseC = c > 0 && !(s.size() >= 2 && s[s.size()-1] == 'c' && s[s.size()-2] == 'c');

//         if(canUseA && canUseB && canUseC){
//             if(a >= b && a >=c){
//                 s += 'a';
//                 a--;
//             } else if( b >= a && b >= c){
//                 s += 'b';
//                 b--;
//             } else{
//                 s += 'c';
//                 c--;
//             }
//         } else if(canUseA && canUseB){
//             if(a >= b){
//                 s += 'a';
//                 a--;
//             } else{
//                 s += 'b';
//                 b--;
//             }
//         } else if(canUseA && canUseC){
//             if(a >= c){
//                 s += 'a';
//                 a--;
//             } else{
//                 s += 'c';
//                 c--;
//             }
//         } else if(canUseB && canUseC){
//             if(b >= c){
//                 s += 'b';
//                 b--;
//             } else{
//                 s += 'c';
//                 c--;
//             }
//         } else if(canUseA){
//             s += 'a';
//             a--;
//         } else if(canUseB){
//             s += 'b';
//             b--;
//         } else if(canUseC){
//             s += 'c';
//             c--;
//         } else{
//             return s;
//         }
//     }

//     return s;
// }

// This can be done using Max-Heap too, it won't matter much for this exact problem,
// but that simplifies the code for a problem with k distinct letter, where k is large,
// instead of being just 3.

#include <string>
#include <queue>
using namespace std;

string longestDiverseString(int a, int b, int c){
    priority_queue<pair<int, char>> maxHeap;

    if(a > 0) maxHeap.push({a, 'a'});
    if(b > 0) maxHeap.push({b, 'b'});
    if(c > 0) maxHeap.push({c, 'c'});

    string s;

    while(!maxHeap.empty()){
        auto [count1, char1] = maxHeap.top();
        maxHeap.pop();

        int len = s.size();

        if(len >= 2 && s[len-1] == char1 && s[len-2] == char1){

            if(maxHeap.empty()){
                break;
            }

            auto [count2, char2] = maxHeap.top();
            maxHeap.pop();

            s += char2;
            count2 --;

            if(count2 > 0){
                maxHeap.push({count2, char2});
            }

            maxHeap.push({count1, char1});
        } else{
            s += char1;
            count1 --;

            if(count1 > 0){
                maxHeap.push({count1, char1});
            }
        }

    }

    return s;
}