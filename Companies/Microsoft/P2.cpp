/*
You are given an integer n where n is divisible by 4.
Find an integer x such that: x >= n, 
The number of bits in the binary representation of x is equal to that of n, 
The value v = n ^ (n+1) ^ (n+2) ^ ... ^ x is maximized (here ^ stands for xor operation) 
If multiple values of x produce the same maximum value of v, return the smallest such x.
*/

#include <iostream>
#include <cmath>
using namespace std;

long long findX(long long n){
    int b = 0; // to store the number of bits needed to store n
    long long temp = n;
    while(temp > 0){
        b++;
        temp = temp >> 1; // right shift temp by 1 bit
    }

    return pow(2, b) - 2;
    
}

int main(){
    long long n = 16;
    long long x = findX(n);
    cout << x;
    return 0;
}