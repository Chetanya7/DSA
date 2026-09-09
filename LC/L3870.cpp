using namespace std;

// Given n <= 10^5

int countCommas(int n){
    if(n < 1000){
        return 0;
    }

    int count = n - 1000 + 1;
    return count;
}