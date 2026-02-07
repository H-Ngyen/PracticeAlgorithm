#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

long long powll(long long a, long long b) {
    a %= MOD; 
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main () {
    cout << powll(2,3);
}