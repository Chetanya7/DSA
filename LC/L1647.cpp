#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int minDeletions(string s){
    unordered_map<char, int> freqMap;
    for(char c: s){
        freqMap[c]++;
    }

    unordered_set<int> used;
    int deletions;

    for(auto& [ch, freq]: freqMap){
        while(freq > 0 && used.count(freq)){
            freq--;
            deletions++;
        }

        if(freq > 0){
            used.insert(freq);
        }
    }

    return deletions;
}