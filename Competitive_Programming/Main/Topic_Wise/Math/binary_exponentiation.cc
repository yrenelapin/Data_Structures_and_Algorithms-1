#include <bits/stdc++.h>
using namespace std;

// Computes a^b in O(log(b)). This is better.
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) // Check if the number is odd.
            res = res * a;
        a = a * a;
        b >>= 1;   // b = b >> 1  which means dividing by 2. 
    }
    return res;
}

// It is  recursive implemetation of above.
long long binpow_rec(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow_rec(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


int main(){}